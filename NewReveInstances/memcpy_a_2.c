//#include "blosc-common.h"
/*
 * Detect if the architecture is fine with unaligned access.
 */
#if !defined(BLOSC_STRICT_ALIGN)
#define BLOSC_STRICT_ALIGN
#if defined(__i386__) || defined(__386) || defined (__amd64)  /* GNU C, Sun Studio */
#undef BLOSC_STRICT_ALIGN
#elif defined(__i486__) || defined(__i586__) || defined(__i686__)  /* GNU C */
#undef BLOSC_STRICT_ALIGN
#elif defined(_M_IX86) || defined(_M_X64)   /* Intel, MSVC */
#undef BLOSC_STRICT_ALIGN
#elif defined(__386)
#undef BLOSC_STRICT_ALIGN
#elif defined(_X86_) /* MinGW */
#undef BLOSC_STRICT_ALIGN
#elif defined(__I86__) /* Digital Mars */
#undef BLOSC_STRICT_ALIGN
/* Seems like unaligned access in ARM (at least ARMv6) is pretty
   expensive, so we are going to always enforce strict aligment in ARM.
   If anybody suggest that newer ARMs are better, we can revisit this. */
/* #elif defined(__ARM_FEATURE_UNALIGNED) */  /* ARM, GNU C */
/* #undef BLOSC_STRICT_ALIGN */
#elif defined(_ARCH_PPC) || defined(__PPC__)
/* Modern PowerPC systems (like POWER8) should support unaligned access
   quite efficiently. */
#undef BLOSC_STRICT_ALIGN
#endif
#endif


static inline unsigned char *copy_4_bytes(unsigned char *out, const unsigned char *from) {
#if defined(BLOSC_STRICT_ALIGN)
  uint32_t chunk;
  memcpy(&chunk, from, 4);
  memcpy(out, &chunk, 4);
#else
  *(uint32_t *) out = *(uint32_t *) from;
#endif
  return out + 4;
}

extern int __mark(int);

int memcpy(int *dest, int *src, int size) {
   int *start = src;
   while(__mark(42) & (src - start < size)) {
      *dest = *src;
      dest++;
      src++;
   }
   return 1;
}
