/*  RAL-CGM Interpreter header file
 *
 *  Linux specific setting for CGM interpreter
 */

/*  Define Machine  */

#define LINUX

/*  Define Graphics system(s)  */

#define POSTSCRIPT
#define BEZIER
#define HERSHEY
#define XW

#define DATADIR "../data/"

#define NAMELGTH  32
#define EXTLGTH    8

#define Posint64 unsigned long long
#define MALLOCH
#include <stdlib.h>

#ifdef CGMOXW_C      /* X-Window specific settings  */

#include <X11/cursorfont.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

#endif
