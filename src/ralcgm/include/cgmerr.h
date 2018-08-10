/*   RAL-CGM interpreter header file:  @(#) cgmerr.h  version 3.5
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
 * Description:  CGM error messages and codes
 *
 * Modification log:
 *
 *   2 Aug 91 RTP  Add SCCS id
 *  11 Sep 91 CDS  Split of utility specific stuff to leave just 'user'
 *                 bits
 *   3 Nov 94 KEVP Add function CGMerrcount to enable output driver to obtain
 *                 the error count. It may raise cgmerrcount by that amount to enable
 *                 picture to be reshown (useful for output driver with frame menu).
 *  28 Feb 95 KEVP Add errors messages for zero character orientation vector
 */

#ifndef CGMERR_H
#define CGMERR_H

/*  Include the files on which this is dependent.  */

#include "cgmtypes.h"

#ifdef CGMINIT_H
FILE *cgmerr;
#else
extern FILE *cgmerr;
#endif

/*  Error function call */
int CGMerror(char *, int, Enum, char *);

/* Get Error Count */
int CGMcounterr(void);

/*  Macro to make life a little simpler  */

#define CGMERROR (void) CGMerror

/*  Error categories */

#define  WARNING    (Enum) 1
#define  ERROR      (Enum) 2
#define  FATAL      (Enum) 3

/*  Return Codes - (System Dependent) */

#ifndef  RC_FILERR
#define  RC_FILERR  (Index) 28
#endif
#ifndef  RC_FATAL
#define  RC_FATAL   (Index) 99
#endif
#define  RC_NULL    (Index)  0

/*  Error codes */

#define  ERR_NOTFOUND     -1
#define  ERR_MANYERR     100
#define  ERR_APNDTXT     101
#define  ERR_BIGCELL     102
#define  ERR_BIGEDGES    103
#define  ERR_BIGINTS     104
#define  ERR_BIGPATT     105
#define  ERR_BIGPOINTS   106
#define  ERR_BIGSTR      107
#define  ERR_DIRCELL     108
#define  ERR_DIRPATT     109
#define  ERR_ELEMENT     110
#define  ERR_ENCODING    111
#define  ERR_EOF         112
#define  ERR_FEWPNTS     113
#define  ERR_FONTFILE    114
#define  ERR_INTCHR      115
#define  ERR_INVATT      116
#define  ERR_INVCOLR     117
#define  ERR_INVCONT     118
#define  ERR_INVDELIM    119
#define  ERR_INVELEM     120
#define  ERR_INVENUM     121
#define  ERR_INVESC      122
#define  ERR_INVMFDESC   123
#define  ERR_INVOPCODE   124
#define  ERR_INVOUT      125
#define  ERR_INVPDESC    126
#define  ERR_INVPRIM     127
#define  ERR_MAXCOLR     128
#define  ERR_MENUFONT    129
#define  ERR_MFOPEN      130
#define  ERR_NOBACKSP    131
#define  ERR_NOCLT       132
#define  ERR_NOCODE      133
#define  ERR_NOFONT      134
#define  ERR_NOGDP       135
#define  ERR_NOMEMORY    136
#define  ERR_NOTAPNDTXT  137
#define  ERR_NOTCGM      138
#define  ERR_NOTERM      139
#define  ERR_OPENFILE    140
#define  ERR_PATINDEX    141
#define  ERR_PATTABLE    142
#define  ERR_PICOPEN     143
#define  ERR_REDIRECT    144
#define  ERR_SEEKEOF     145
#define  ERR_VERSION     146
#define  ERR_DIRCOL      147
#define  ERR_HUFFMAN     148
#define  ERR_STATE       149
#define  ERR_NAME2LONG   150
#define  ERR_INVARG      151
#define  ERR_INVASF      152
#define  ERR_RALGKS111   153
#define  ERR_NOENDPIC    154
#define  ERR_NODRIVER    155
#define  ERR_RANDOM      156
#define  ERR_INVOPT      157
#define  ERR_NOFILE      158
#define  ERR_CELL2SMALL  159
#define  ERR_ELMNOTSUP   160
#define  ERR_BADPENDEF   161
#define  ERR_PICLGRPAP   162
#define  ERR_GDIFAIL     163

/*  General font system messages  */

#define  ERR_NOCSETS     200
#define  ERR_BADCSETS    201
#define  ERR_NOFAMS      202
#define  ERR_BADFAMS     203
#define  ERR_NOFAMSYN    204
#define  ERR_BADFAMSYN   205
#define  ERR_NODSN       206
#define  ERR_BADDSN      207
#define  ERR_CSETRANGE   208
#define  ERR_CSETUNKNOWN 209
#define  ERR_FONTRANGE   210
#define  ERR_METHOD      211
#define  ERR_NOMETHODS   212
#define  ERR_METHRANGE   213
#define  ERR_NOREQFONTS  214
#define  ERR_PACKMISSING 215
#define  ERR_NOFMATCH    216
#define  ERR_NOFSETS     217
#define  ERR_BADFSETS    218
#define  ERR_XSFPERM     219
#define  ERR_XSISOCSETS  220
#define  ERR_XSISOFONTS  221
#define  ERR_XSFAMILY    222
#define  ERR_XSALIAS     223
#define  ERR_XSDESIGN    224
#define  ERR_XSSOURCE    225
#define  ERR_XSSFONTS    226
#define  ERR_XSRFONTS    227
#define  ERR_NOFNTSPACE  228
#define  ERR_XFONTLIST   229
#define  ERR_XOPENDISP   230

/*  Bezier font system messages  */

#define  ERR_BEZDIR      250
#define  ERR_BEZDBAD     251
#define  ERR_NOFONTS     252
#define  ERR_BEZOPEN     253
#define  ERR_BEZNODEF    254
#define  ERR_DBUNAV      255
#define  ERR_NPCINSTR    256
#define  ERR_FNTNOTSUP   257
#define  ERR_CURVE2BIG   258
#define  ERR_FNTNOTOPEN  259
#define  ERR_COMPZERO    260
#define  ERR_FILCOR      261

/*  Text and PostScript system messages  */

#define  ERR_NOPROLG     300
#define  ERR_NOALIAS     301
#define  ERR_TXTSYSNFND  302
#define  ERR_2MANYFILES  303
#define  ERR_CHBASEZERO  304
#define  ERR_CHUPZERO    305

/* Polygon and Polygon Set messages */

#define  ERR_NOMEMPSL    400
#define  ERR_BADEDGETAB  401

#endif     /* end of cgmerr.h  */
