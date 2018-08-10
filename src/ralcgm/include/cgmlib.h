/*  RAL-CGM Interpreter header file: @(#) cgmlib.h  version 3.2
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
 * Description: User callable library for CGM calls
 *
 * Modification log:
 *
 *  16 Jun 90 RTPCreated
 *   2 Aug 91 RTP  Add SCCS id
 */

#ifndef CGMLIB_H
#define CGMLIB_H

/*  External variables */

#ifdef CGMLIB_C      /* Library entry */

#include "cgmpar.h"
#include "cgmin.h"

extern FILE *cgmo;
extern Enum cgmdriver;
extern Logical cgmerrcount;


#else             /*  User entry point */

#include "cgminit.h"

FILE *cgmo, *cgmi = NULL;


#endif


void cgminit(Enum, char *);  /*  Initialise CGM output */
void CGMout(Code, long *, float *, char *);

int CGMerror(char *, int, Enum, char *);

/*  Define functions as 6 character names for portability */

#define  m_begmf           M_BGMF
#define  m_endmf           M_ENMF
#define  m_begpic          M_BGP
#define  m_begpicbody      M_BGPB
#define  m_endpic          M_ENDP
#define  m_mfversion       M_MFV
#define  m_mfdesc          M_MFD
#define  m_vdctype         M_VDC
#define  m_integerprec     M_IP
#define  m_realprec        M_RP
#define  m_indexprec       M_IXP
#define  m_colrprec        M_CP
#define  m_colrindexprec   M_CIXP
#define  m_maxcolrindex    M_MCI
#define  m_colrvalueext    M_CX
#define  m_mfelemlist      M_MFEL
#define  m_begmfdefaults   M_BMFD
#define  m_endmfdefaults   M_EMFD
#define  m_fontlist        M_FL
#define  m_charsetlist     M_CHS
#define  m_charcoding      M_CHCA
#define  m_scalemode       M_SCM
#define  m_colrmode        M_CSM
#define  m_linewidthmode   M_LNWS
#define  m_markersizemode  M_MKSS
#define  m_edgewidthmode   M_EDWS
#define  m_vdcext          M_VDCX
#define  m_backcolr        M_BC
#define  m_vdcintegerprec  M_VDCI
#define  m_vdcrealprec     M_VDCR
#define  m_auxcolr         M_XC
#define  m_transparency    M_TR
#define  m_cliprect        M_CLRC
#define  m_clip            M_CLIP
#define  m_line            M_PL
#define  m_disjtline       M_DJPL
#define  m_marker          M_PMK
#define  m_text            M_TX
#define  m_restrtext       M_RDTX
#define  m_apndtext        M_APTX
#define  m_polygon         M_PG
#define  m_polygonset      M_PGS
#define  m_cellarray       M_CA
#define  m_gdp             M_GDP
#define  m_rect            M_RC

#define  m_circle          M_CIR
#define  m_arc3pt          M_A3P
#define  m_arc3ptclose     M_A3PC
#define  m_arcctr          M_AC
#define  m_arcctrclose     M_ACC
#define  m_ellipse         M_EL
#define  m_elliparc        M_ELA
#define  m_elliparcclose   M_ELAC
#define  m_lineindex       M_LNBI
#define  m_linetype        M_LN
#define  m_linewidth       M_LNW
#define  m_linecolr        M_LNC
#define  m_markerindex     M_MKBI
#define  m_markertype      M_MK
#define  m_markersize      M_MKS
#define  m_markercolr      M_MKC
#define  m_textindex       M_TXBI
#define  m_textfontindex   M_TXFI
#define  m_textprec        M_TXP
#define  m_charexpan       M_CHXF
#define  m_charspace       M_CHSP
#define  m_textcolr        M_TXC
#define  m_charheight      M_CHH
#define  m_charori         M_CHOR
#define  m_textpath        M_TXPA
#define  m_textalign       M_TXAL
#define  m_charsetindex    M_CHSI
#define  m_altcharsetindex M_ACHS
#define  m_fillindex       M_FBI
#define  m_intstyle        M_IS
#define  m_fillcolr        M_FC
#define  m_hatchindex      M_HAI
#define  m_patindex        M_PAI
#define  m_edgeindex       M_EDBI
#define  m_edgetype        M_ED
#define  m_edgewidth       M_EDW
#define  m_edgecolr        M_EDC
#define  m_edgevis         M_EDV
#define  m_fillrefpt       M_FRFP
#define  m_pattable        M_PAT
#define  m_patsize         M_PAS
#define  m_colrtable       M_CT
#define  m_asf             M_ASF
#define  m_escape          M_ESC
#define  m_message         M_MESS
#define  m_appldata        M_AP

#define  CGMconvert_points CGMCONVP

/*  Metafile Delimiter elements */

void  m_begmf(char *);

void  m_endmf(void);

void  m_begpic(char *);

void  m_begpicbody(void);

void  m_endpic(void);

/*  Metafile Descriptor Elements */

void  m_mfversion(int);

void  m_mfdesc(char *);

void  m_vdctype(Enum);

void  m_integerprec(int);

void  m_realprec(int, int, int, Enum);

void  m_indexprec(int);

void  m_colrprec(int);

void  m_colrindexprec(int);

void  m_maxcolrindex(int);

void  m_colrvalueext(RGBcolour, RGBcolour);

void  m_mfelemlist(int, Code *);

void  m_begmfdefaults(void);

void  m_endmfdefaults(void);

void  m_fontlist(int, char **);

void  m_charsetlist(int, int *, char **);

void  m_charcoding(Enum);

/*  Picture Descriptor elements */

void  m_scalemode(Enum, float);

void  m_colrmode(Enum);

void  m_linewidthmode(Enum);

void  m_markersizemode(Enum);

void  m_edgewidthmode(Enum);

void  m_vdcext(Point, Point);

void  m_backcolr(RGBcolour);

/*  Control elements  */

void  m_vdcintegerprec(int);

void  m_vdcrealprec(int, int, int, Enum);

void  m_auxcolr(Colour);

void  m_transparency(Enum);

void  m_cliprect(Point, Point);

void  m_clip(Enum);

/*  Graphical Primitives */

void  m_line(int, Point *);

void  m_disjtline(int, Point *);

void  m_marker(int, Point *);

void  m_text(Point, Enum, char *);

void  m_restrtext(Point, Point, Enum, char *);

void  m_apndtext(Enum, char *);

void  m_polygon(int, Point *);

void  m_polygonset(int, Point *, Enum *);

void  m_cellarray(Point, Point, Point, int, int,
                  Indexcolour *, RGBcolour *);

void  m_gdp(int, int, Point *, char *);

void  m_rect(Point, Point);

void  m_circle(Point, Point, float);

void  m_arc3pt(Point, Point, Point);

void  m_arc3ptclose(Point, Point, Point, Enum);

void  m_arcctr(Point, Point, Point, float);

void  m_arcctrclose(Point, Point, Point, float, Enum);

void  m_ellipse(Point, Point, Point);

void  m_elliparc(Point, Point, Point, Point, Point);

void  m_elliparcclose(Point, Point, Point, Point, Point, Enum);

/*  Attributes */

void  m_lineindex(Index);

void  m_linetype(Index);

void  m_linewidth(float);

void  m_linecolr(Colour);

void  m_markerindex(Index);

void  m_markertype(Index);

void  m_markersize(float);

void  m_markercolr(Colour);

void  m_textindex(Index);

void  m_textfontindex(Index);

void  m_textprec(Enum);

void  m_charexpan(float);

void  m_charspace(float);

void  m_textcolr(Colour);

void  m_charheight(float);

void  m_charori(Vector, Vector);

void  m_textpath(Enum);

void  m_textalign(Enum, Enum, float, float);

void  m_charsetindex(Index);

void  m_altcharsetindex(Index);

void  m_fillindex(Index);

void  m_intstyle(Enum);

void  m_fillcolr(Colour);

void  m_hatchindex(Index);

void  m_patindex(Index);

void  m_edgeindex(Index);

void  m_edgetype(Index);

void  m_edgewidth(float);

void  m_edgecolr(Colour);

void  m_edgevis(Enum);

void  m_fillrefpt(Point);

void  m_pattable(Index, int, int, Prec, Colour *);

void  m_patsize(Vector, Vector);

void  m_colrtable(Index, int, RGBcolour *);

void  m_asf(int, Code *, Enum *);

/* Escape and External elements */

void  m_escape(int, char *);

void  m_message(Enum, char *);

void  m_appldata(int, char *);


#endif  /*  end of cgmlib.h */
