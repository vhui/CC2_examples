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

__attribute__((always_inline))
static char *strchr(register const char *t, int c) {
    register char ch;

    ch = c;
    for (;;) {
        if (*t == ch)
            break;
        if (!*t)
            return 0;
        ++t;
        __mark(0);
    }
    return (char *)t;
}

size_t strcspn(const char *s, const char *reject) {
    size_t count = 0;

    while (__mark(1) & (*s)) {
        char ch = *s++;
        if (strchr(reject, ch) == NULL) {
            ++count;
        } else {
            return count;
        }
    }

    return count;
}

//////////////////////////////////////
#include <string.h>

char*strtok_r(char*s,const char*delim,char**ptrptr) {
  char*tmp=0;

  if (s==0) s=*ptrptr;
  s+=strspn(s,delim);		/* overread leading delimiter */
  if (__likely(*s)) {
    tmp=s;
    s+=strcspn(s,delim);
    if (__likely(*s)) *s++=0;	/* not the end ? => terminate it */
  }
  *ptrptr=s;
  return tmp;
}