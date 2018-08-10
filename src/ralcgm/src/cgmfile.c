/*   RAL-CGM Interpreter module:  @(#) cgmfile.c  version 3.3
 *
 * Copyright (C) Rutherford Appleton Laboratory 1990, All Rights Reserved.
 *
 * This source may be copied, distributed, altered or used, but not sold
 * for profit or incorporated into a product except under licence from
 * the author.
 * It is not in the public domain.
 * This notice should remain in the source unaltered, and any changes to
 * the source made by persons other than the author should be marked as
 * such.
 *
 * R T Platon @ Rutherford Appleton Laboratory (rtp@uk.ac.rl.ib)
 *
 * Description:  System independent file handling Utilities
 *
 * Maintenance Log:
 *   4 Oct 90 RTP  Original version created from cgminput.c to separate
 *                   file handling routines.
 *  13 Nov 90 PLP  Introduced environment variable CGMDATA.
 *  14 Dec 90 RTP  Replace 'sqrt' and 'fabs' by macros SQRT and FABS
 *   7 Jan 91 RTP  Use MAXFLSIZE for 'tmp' char array
 *  10 Jan 91 RTP  Add C370 options for CMS, increase fmode to 80 chars
 *  12 Apr 91 AMR  Added CGMmodfextn, CGMmodfname and CGMgetfname. Moved from
 *                 the PostScript driver.
 *  14 Apr 91 RTP  Remove PATHDELIM definition, put in cgmmach.h/mc_*.h
 *  14 May 91 RTP  Add ANSI declarations
 *  17 May 91 RTP  Cast malloc arguments to (size_t)
 *  20 May 91 RTP  Change free() calls to Macro FREE
 *   6 Jun 91 RTP  Add 1 to size for malloc for filename
 *  19 Jun 91 RTP  Add header file cgmatt.h to include function declarations
 *  29 Jul 91 NMH  VMS Binary cgms now output in 512 byte fixed length records
 *  30 Jul 91 NMH  Force stream mode access on input and binary output for VMS
 *   2 Aug 91 RTP  Add SCCS id
 *   7 Aug 91 RTP  Tidy up after lint
 *  23 Sep 91 NMH  Added "bls=512" for VMS binary output.
 *   3 Mar 92 RTP  Add IBM RS6000
 *  10 Feb 94 RTP  Move definition of DMESS to cgmmach.h
 *   24 Jul 94 KEVP In CGMfopen put in binary option for BORLANDC
 */



#include "../include/cgmmach.h"
#include "../include/cgmpar.h"
#include "../include/cgmerr.h"
#include "../include/cgmfile.h"

/********************************************************* CGMpath ***/

char *CGMpath(char *filename, char *extension)

/*
 *    CGMpath(): Function to build up a  full pathname in a (hopefully)
 *               system independent way.
 *
 *               IN: Base name part of the filename (i.e. no extension).
 *                   File extension part of the filename.
 *               OUT: None.
 *               RETURN VALUE: Pointer to the fully-built pathname.
 *
 *               Author: PLP
 *
 * ALGORITHM
 * ---------
 *
 * Allocate memory needed to store the entire pathname, which consists of
 * the data directory name (macro DATADIR defined in mach.h), filename's
 * base name, file separator (macro FILESEP defined in mach.h) and the
 * file extension.
 *
 * NB: If malloc fails we exit on the spot.
 *
 * LOCALS
 * ------
 * func - function identifier to pass down to the error handler.
 * ptr  - pointer to the fully built pathname.
 * tmp  - temporary string.
 *
 */

{
    char *ptr, *func = "CGMpath";
    char tmp[MAXFLSIZE + 1];
    static char *datapath = (char *) NULL;

    /* Check input arguments - issue warning if illegal length */
    if ((strlen(filename) > NAMELGTH || !strlen(filename)) ||
        (strlen(extension) > EXTLGTH || !strlen(extension))) {
        (void) sprintf(tmp, "%s%s%s", filename, FILESEP, extension);
        (void) CGMerror(func, ERR_NAME2LONG, WARNING, tmp);
    }

    if (datapath == (char *) NULL) {
        datapath = (char *) getenv("CGMDATA");
        if (datapath == (char *) NULL) datapath = DATADIR;
    }
    /* Get enough memory for the entire filename */
    ptr = (char *) malloc((size_t) (strlen(datapath) + strlen(filename)
                                    + strlen(FILESEP) + strlen(extension) + 1));
    if (ptr == NULL)
        /* Exit on the spot if malloc failed */
        exit(CGMerror(func, ERR_NOMEMORY, FATAL, NULLSTR));
    else {
        /* Build up the four part filename */
        (void) sprintf(ptr, "%s%s%s%s", datapath, filename, FILESEP, extension);
    }
    return ptr;
}

/********************************************************* CGMfopen ****/

FILE *CGMfopen(char *filename, char mode, Enum type)

/*
 *    CGMfopen(): Function to open a file in a system independent way.
 *
 *               IN: file name
 *                   mode ( F_READ or F_WRITE )
 *                   type ( BINARY, CHARACTER  or CLEAR_TEXT )
 *               OUT: None.
 *               RETURN: Return code from fopen (*FILE)
 *
 *               Author: RTP
 *
 */

{
    char fmode[80], *fname;
#if LFILEDEF > 0
    char *func="CGMfopen";
#endif
    FILE *file;

#if LFILEDEF > 0
    fname = (char *)malloc( (size_t) (strlen(filename) + LFILEDEF) );
    if( fname == NULL)
       /* Exit on the spot if malloc failed */
       exit ( CGMerror(func, ERR_NOMEMORY, FATAL, NULLSTR));
    strcpy(fname, filename);
#else
    fname = filename;
#endif
    sprintf(fmode, "%c", mode);






    file = fopen(fname, fmode);

#ifdef DEBUG
    (void) fprintf(stderr, "Open file: '%s' '%s' %x\n",
                   fname, fmode, file );
#endif
#if LFILEDEF > 0
    FREE ( fname );
#endif

    return file;
}

/***********************************************************************
* CGMmodfextn()  : modify the extension of a filename.
*
* Input Arguments:
*     extension  : new extension
*
* Input/Output Arguments:
*     filename   : address of the filename to modify
*
* Return value   :
*     None
*
* Algorithm      :
*     This routine is system dependant!
*     Uses PATHDELIM to determine where the extension is within the filename,
*       then replaces it with the new extension.
*     Not possible to use FILESEP, defined in mach.h, in tests
*       due to double quotes rather than apostrophes being used, so assign it
*       at the beginning, then use the first character when comparing.
*     For cms there may be a filemode following the extension, therefore
*       a copy is used to search, while constructing the original again.
*
* Maintenance Log:
*  25 Jul 91 AMR  Fixed a bug in CMS part, where original filename was being
*                 reset before being copied!!
*
* Bugs           :
*     Doesn't check that the resulting filename is valid!
************************************************************************/
void CGMmodfextn(char *fn, char *extn) {
    char *cp1, *filesep = FILESEP;

    /*
     Look through the filename backwards until either ...
       the beginning of the extension is found, or
       the beginning of the filename is found, i.e. no extension, by
         looking for the pathname delimter or the beginning of the string.
    */


    for (cp1 = fn + strlen(fn); cp1 > fn; cp1--)
        if (*cp1 == PATHDELIM) {
            cp1 = fn;        /* no extension, so pretend to have finished the FOR */
            break;
        } else if (*cp1 == *filesep) break;

    /*
     If extension found, remove it by delimiting the string after the separator.
     else, append the separator to the end of the filename.
    */
    if (cp1 != fn)
        *++cp1 = '\0';
    else
        (void) strcat(fn, FILESEP);

    /* Add the new extension to the filename */
    (void) strcat(fn, extn);

}


/***********************************************************************
* CGMmodfname() : modify the extension of a filename.
*
* Input Arguments:
*     newname   : new filename
*
* Input/Output Arguments:
*     fn        : address of the filename to modify
*
* Return value  :
*     None
*
* Algorithm     :
*     This routine is system dependant!
*     Not possible to use MACRO's such as FILESEP, defined in mach.h, in tests
*       due to double quotes rather than apostrophes being used, so assigns it
*       to a string, and uses the first character in order to do comparisons.
*     Uses a copy of the string to search on, and re-constructs the original
*       from it, and the new filename.
*
* Maintenance Log:
*  25 Jul 91 AMR  Added free for fn2.
*
* Bugs          :
*     Doesn't check that the re-constructed filename is valid.
************************************************************************/
void CGMmodfname(char *fn, char *newname) {
    char *cp1, *fn2, *filesep = FILESEP, *func = "CGMmodfname";
    char *extnptr;
    int extnflag = 0;

    fn2 = (char *) malloc((size_t) (sizeof(char) * (strlen(fn) + 1)));

    if (fn2 == NULL)
        exit((int) CGMerror(func, ERR_NOMEMORY, FATAL, NULLSTR));

    (void) strcpy(fn2, fn);



    for (cp1 = fn2 + strlen(fn2); cp1 >= fn2; cp1--)

        /*
         Search backwards through the string, setting a pointer at the extension
         delimeter, and stopping when the beginning of the filename is reached
         by looking for the pathname delimeter or the beginning of the string.
        */
        if ((*cp1 == *filesep) && (extnflag == 0)) {
            extnptr = cp1;
            extnflag = 1;
        } else if (*cp1 == PATHDELIM)
            break;
    /*
     truncate the file at the end of the pathname, then add then new filename
     and then the old extension
    */
    *(fn + (++cp1 - fn2)) = '\0';
    (void) strcat(fn, newname);
    (void) strcat(fn, extnptr);


    FREE(fn2);

}

/***********************************************************************
* CGMgetfname() : locate the end of the pathname part of a given file, and
*                 return the length of the filename base.
* Input Arguments:
*     fname     : the complete filename (path, filename base and extension)
*                 to search
*
* Input/Output Arguments:
*     fnptr     : address pointer to end of pathname.
*
* Return value:
*     fnlen     : the length of the base part of the filename.
*
* Algorithm     :
*     This routine is system dependant!
*     Not possible to use MACRO's such as FILESEP, defined in mach.h, in tests
*       due to double quotes rather than apostrophes being used, so assigns it
*       to a string, and uses the first character in order to do comparisons.
*
************************************************************************/
unsigned short CGMgetfname(char *fname, char **fnptr) {
    char *filesep = FILESEP;
    char *fsptr, *cptr;
    unsigned short fnlen, extnflag = 0;



    /*
     Search for the LAST separator in the filename, and the pathname/filename
     delimiter.
    */
    for (cptr = fname + strlen(fname); cptr >= fname; cptr--)

        if ((*cptr == *filesep) && (extnflag == 0)) {
            fsptr = cptr;
            extnflag = 1;
        } else if (*cptr == PATHDELIM)
            break;

    *fnptr = ++cptr;
    fnlen = (extnflag == 1 ? (fsptr - *fnptr)
                           : fname + strlen(fname) - *fnptr);


    return (fnlen);
}
