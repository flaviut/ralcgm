/*   RAL-CGM interpreter module:  @(#) cgmfile.c  version 3.3
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
 *  13 Nov 90 PLP  introduced environment variable CGMDATA.
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



#include "cgmmach.h"
#include "cgmpar.h"
#include "cgmerr.h"
#include "cgmfile.h"

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
    FILE *file;
    fname = filename;
    sprintf(fmode, "%c", mode);


    file = fopen(fname, fmode);
    return file;
}