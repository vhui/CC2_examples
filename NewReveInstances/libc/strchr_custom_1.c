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

/*static char *strchr(register const char *t, int c) {
    register char ch;

    ch = c;
    for (;__mark(0);) {
        if (*t == ch)
            break;
        if (!*t)
            return 0;
        ++t;
    }
    return (char *)t;
} */    //ORIGINAL!

char *strchr(const char *s, int c_in) {
    unsigned char c;

    c = (unsigned char)c_in;

    for (;__mark(42);) {
        if (*s == c)
            return (char *)s;
        else if (*s == '\0')
            return NULL;
        if (*++s == c)
            return (char *)s;
        else if (*s == '\0')
            return NULL;
        if (*++s == c)
            return (char *)s;
        else if (*s == '\0')
            return NULL;
        if (*++s == c)
            return (char *)s;
        else if (*s == '\0')
            return NULL;
    }
    return NULL;
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
