/*! @file
 * \brief Macro definitions
 *
 * <pre>
 * -- Distributed SuperLU routine (version 1.0) --
 * Lawrence Berkeley National Lab, Univ. of California Berkeley.
 * September 1, 1999
 * </pre>
 */

#ifndef __SUPERLU_CNAMES /* allow multiple inclusions */
#define __SUPERLU_CNAMES

/*
 * These macros have been substantially changed from their original 
 * versions since there seems to be ambiguity as to whether they are being
 * used for C to call Fortran APIs (especially BLAS/LAPACK) or for Fortran
 * to call C routines (such as in the FORTRAN/ folder). Since the ISO C 
 * interface for F90 was likely introduced after these macros were created, 
 * I am going to ignore the latter.
 *
 * Furthemore, rather than defining a single macro, it is important to note
 * that, on a single system, the underscore convention for BLAS and LAPACK
 * routines can be different. In particular, I have run into this on 
 * Blue Gene/P.
*/

#define ADD_       0
#define NOCHANGE   1

#ifdef Add_
# define F77_CALL_C ADD_
# define SUPERLU_FORT(name) name ## _
# define SUPERLU_BLAS(name) name ## _
# define SUPERLU_LAPACK(name) name ## _
#else
# define F77_CALL_C NOCHANGE
# define SUPERLU_FORT(name) name
# define SUPERLU_BLAS(name) name
# define SUPERLU_LAPACK(name) name
#endif

#endif /* __SUPERLU_CNAMES */
