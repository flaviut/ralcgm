/*  RAL-CGM Interpreter header file: @(#) cgmtext.h  version 3.2
 *
 * Copyright (C) Rutherford Appleton Laboratory 1990, All Rights Reserved.
 *
 * This source may be copied, distributed, altered or used, but not sold
 * for profit or incorporated into a product except under licence from
 * the authors.
 *
 * It is not in the public domain.
 *
 * This notice should remain in the source unaltered, and any changes to
 * the source made by persons other than the authors should be marked as
 * such.
 *
 * R T Platon @ Rutherford Appleton Laboratory (rtp@uk.ac.rl.ib)
 *
 * Description:
 *
 *      Header file used by the RAL-CGM Text Utilites
 *
 * Maintenance log:
 *
 *   7 Dec 90 RTP  Use Point type for arguments where appropriate
 *   2 Aug 91 RTP  Add SCCS id
 *   5 Aug 92 RTP  Add prototype for TXTrestrict
 */

#ifndef CGMTEXT_H
#define CGMTEXT_H

/*  Include all files on which this is dependent.  */
#include "cgmtypes.h"
#include "../../ralcgm/include/cgmstruc.h"
#include "../../ralcgm/include/cgmelem.h"
#include "cgmpar.h"
#include "../../ralcgm/include/cgmatt.h"

/* Enumerated types for supported font methods */
#define HDW       (Enum) 1                       /* Hardware */
#define PS        (Enum) 2                       /* PostScript */
#define BEZ       (Enum) 3                       /* Bezier */
#define HER       (Enum) 4                       /* Hershey */
#define TEX       (Enum) 5                       /* TeX (MetaFont) */

/* Transparency flags */
#define YES_TRANS 0
#define NO_TRANS 1

#define MAX_FONT_CHARS 95   /* Maximum Number of Characters in Font */

/* Typedef for the text item structure */
typedef struct textitem {
    /* CGM attributes that can be changed from TEXT to APNDTEXT ... */
    char *str;
    Index text_font, altext_font, char_set, altchar_set;
    Enum text_prec, text_method, altext_method;
    float char_exp, char_space, char_height;
    Index colourindex, aux_colourindex;
    RGBcolour text_col, aux_col;
    Enum colour_mode, transparency;
    float text_hcont, text_vcont;

    /* font details information:
       rmaxwd   Width of widest character
       rbot     Distance from base to bottom line
       rtop     Distance from cap to top line
       rwd      Character widths array

    */
    float rmaxwd, rbot, rtop, rwd[MAX_FONT_CHARS];

    /* pointers to coordinates of origins of each character in the string */
    Point *origin;

    /* height and width of the bounding box of a substring item */
    float tbxwid, tbxheight;

    /* pointer to the next structure, for linking the text items info */
    struct textitem *next;

} Textitem;

/* CGM defaults and attributes are held externally */
extern struct defaults cur;
extern struct attributes curatt;

/* Declare functions accessible outside cgmtext.c */

#ifdef CGMTEXT_C /* Declare without extern if included from cgmtext.c*/
#else
#endif


Textitem *TXTaccinf(long, char *, struct textatt *, Enum *);

Textitem *TXTrestrict(Textitem *, double, double, struct textatt *);

void TXTalign(Textitem *, Point, double, double);

void TXTfree(Textitem *);

double TXTgwidth(Textitem *);

double TXTgheight(Textitem *);

void TXTxform(Point, Tmatrix);

#ifdef POSTSCRIPT   /* Conditionally declare font details functions */

void PSgetfd(Textitem *);

#endif
#ifdef BEZIER

void BEZgetfd(Textitem *);

#endif
#ifdef HERSHEY

void HERgetfd(Textitem *);

#endif


#endif   /* end of cgmtext.h */