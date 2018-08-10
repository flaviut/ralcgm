/*   RAL-CGM Interpreter header file:  @(#) cgmfont.h  version 3.1
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
 * Description: structures and variables used by the font system.
 *
 * Modification log:
 *
 *  11 Feb 91 RTP  Tidy up ANSI prototypes
 *   2 Aug 91 RTP  Add SCCS id
 *  10 Sep 91 CDS  Remove utility specific bits to new header file
 *                 cgmufont.h
 *   5 Aug 92 RTP  Add prototype for FNTscale
 *  16 Nov 92 CDS  Changed ifdef ANSI to ifdef PROTO in function prototypes
 */

#ifndef CGMFONT_H
#define CGMFONT_H

void FNTinit(void);

void FNTmatch(struct textatt *, Enum *, Enum *, Index *);

void FNTdebug(int);

void FNTdisplay(void);

Logical FNTscale(Enum *, int *, float *, float, float);


#endif /* End of CGMFONT_H */
