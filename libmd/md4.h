/* MD4.H - header file for MD4C.C
 * $FreeBSD: release/11.0.0/lib/libmd/md4.h 282736 2015-05-10 21:21:52Z thomas $
 */

/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
   rights reserved.

   License to copy and use this software is granted provided that it
   is identified as the "RSA Data Security, Inc. MD4 Message-Digest
   Algorithm" in all material mentioning or referencing this software
   or this function.
   License is also granted to make and use derivative works provided
   that such works are identified as "derived from the RSA Data
   Security, Inc. MD4 Message-Digest Algorithm" in all material
   mentioning or referencing the derived work.

   RSA Data Security, Inc. makes no representations concerning either
   the merchantability of this software or the suitability of this
   software for any particular purpose. It is provided "as is"
   without express or implied warranty of any kind.

   These notices must be retained in any copies of any part of this
   documentation and/or software.
 */

#ifndef _MD4_H_
#define _MD4_H_

#ifdef _MSC_VER
#include "supp/w32defs.h"
#endif
#ifdef __OS400__
#include "supp/isdefs.h"
#endif

/* MD4 context. */
#ifdef MD_INTERNAL

typedef struct MD4Context {
  u_int32_t state[4];	/* state (ABCD) */
  u_int32_t count[2];	/* number of bits, modulo 2^64 (lsb first) */
  unsigned char buffer[64];	/* input buffer */
} MD4_CTX;

#if !defined(MD4_API) && defined(MD_DLL) && defined(_MSC_VER)
#define MD4_API __declspec(dllexport)
#endif

#else
typedef struct MD4Context MD4_CTX;
#endif

#ifndef MD4_API
#define MD4_API
#endif

#ifdef unix
#include <sys/cdefs.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __FreeBSD__
__BEGIN_DECLS
#endif

#ifdef LIBMD_WITH_PREFIX

/* Ensure libmd symbols do not clash with libcrypto */

#ifndef MD4Init
#define MD4Init		_libmd_MD4Init
#endif
#ifndef MD4Update
#define MD4Update	_libmd_MD4Update
#endif
#ifndef MD4Pad
#define MD4Pad		_libmd_MD4Pad
#endif
#ifndef MD4Final
#define MD4Final	_libmd_MD4Final
#endif
#ifndef MD4End
#define MD4End		_libmd_MD4End
#endif
#ifndef MD4File
#define MD4File		_libmd_MD4File
#endif
#ifndef MD4FileChunk
#define MD4FileChunk	_libmd_MD4FileChunk
#endif
#ifndef MD4Data
#define MD4Data		_libmd_MD4Data
#endif

#endif

MD4_API void   MD4Init(MD4_CTX *);
MD4_API void   MD4Update(MD4_CTX *, const void *, unsigned int);
#if 0
void   MD4Pad(MD4_CTX *);
#endif
MD4_API void   MD4Final(unsigned char [16], MD4_CTX *);
MD4_API char * MD4End(MD4_CTX *, char *);
MD4_API char * MD4File(const char *, char *);
MD4_API char * MD4FileChunk(const char *, char *, off_t, off_t);
MD4_API char * MD4Data(const void *, unsigned int, char *);
MD4_API int    MD4ContextSize(void);
MD4_API MD4_CTX *MD4Create(void);
MD4_API void   MD4Destroy(MD4_CTX *);
MD4_API int    MD4DigestSize(void);

#ifdef __FreeBSD__
__END_DECLS
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _MD4_H_ */
