/*  RAL-CGM Interpreter header file: @(#) cgmfill.h  version 3.2
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
 * Description:  CGM Fill area function declarations
 *
 * Modification log:
 *
 *   2 Aug 91 RTP  Add SCCS id
 */

#ifndef CGMFILL_H
#define CGMFILL_H

/* Main Fill Area routine  */
void FILarea(Long, Long *, float *, Enum, Logical,
             void (*)(Long, Point *),
             void (*)(Long, Point *, Enum *));

/* Classify polygon type */
Enum FILpolycheck(Long, Point *);


#endif /* CGMFILLH */
