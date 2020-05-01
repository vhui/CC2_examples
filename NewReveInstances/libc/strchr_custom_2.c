/* openbsd strchr */
#include <string.h>

/*__weak_alias(index, strchr);
__attribute__((always_inline))

char *
strchr(const char *p, int ch)
{
	for (;; ++p) {
		if (*p == (char) ch)
			return((char *)p);
		if (!*p)
			return((char *)NULL);
	}
	// NOTREACHED 
}
DEF_STRONG(strchr);*/ //ORIGINAL

/* glibc */
/*@ rel_in
   (and
      (= s$1 s$2)
      (= reject$1 reject$2)
      (> reject$1 0)
      (forall
         ((i Int))
         (= (select HEAP$1 i) (select HEAP$2 i))))
@*/
#include <stddef.h>
extern int __mark(int);
extern char* __inlineCall(char*);

char *strchr(register const char *t, int c) {
    register char ch;

    ch = c;
    for (;__mark(42);) {
        if (*t == ch)
            break;
        if (!*t)
            return 0;
        ++t;
        if (*t == ch)
            break;
        if (!*t)
            return 0;
        ++t;
        if (*t == ch)
            break;
        if (!*t)
            return 0;
        ++t;
    }
    return (char *)t;
}


size_t strcspn(const char *s, const char *reject) {
    size_t count = 0;

    while (__mark(1) & (*s)) {
        char ch = *s++;
        if (__inlineCall(strchr(reject, ch)) == NULL) {
            ++count;
        } else {
            return count;
        }
    }

    return count;
}
