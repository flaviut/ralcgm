/*   RAL-CGM interpreter module:  @(#) cgmprof.c  version 3.2
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
 * Description:  CGM profile settings
 *
 * Maintenance Log:
 *  18 Mar 91 RTP  Original version created
 *  14 May 91 RTP  Add ANSI declarations
 *   2 Aug 91 RTP  Add SCCS id
 *  10 Feb 94 RTP  Move definition of DMESS to cgmmach.h
 */

#include "cgmin.h"


/*  CGM Utilities in File  */

void CGMprofile(Code);

static void PROindcol(Code);

/* External functions */

void CGMocode(Code);

/**************************************************** CGMprofile *******/

void CGMprofile(Code c) {
    switch (cgmprof) {
        case PROF_CALS:     /* CALS profiling */
        case PROF_GKS:      /* GKS profile */
        case PROF_INDEXCOL: /* Indexed colour only */
            PROindcol(c);
            break;
        case PROF_INTVDC:   /* integer VDC only */
            break;

        default:
            break;
    }


}

/**************************************************** PROindcol ********/

static void PROindcol(Code c) {
    static Logical dircol = FALSE;

    if (c == COLRMODE) {
        dircol = (cur.color_mode == DIRECT);
        if (dircol) cur.color_mode = INDEXED;
    } else if (dircol && cur.color_mode == DIRECT)
        switch (c) {
            case LINECOLR:
            case MARKERCOLR:
            case FILLCOLR:
            case TEXTCOLR:
            case EDGECOLR:
            case CELLARRAY:
                break;
            case COLRTABLE:
                break;
            default:
                break;
        }

    CGMocode(c);
}
