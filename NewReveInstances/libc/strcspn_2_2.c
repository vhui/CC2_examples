/* glibc */
#include <stddef.h>
extern int __mark(int);

size_t strcspn(const char *s, const char *reject) {
    size_t count = 0;

    while (__mark(1) & (*s)) {
        char ch = *s++;
        const char *t = reject;
        for (;__mark(0);) {
            if (*t == ch)
                return count;
            if (!*t) {
                ++count;
                break;
            }
            ++t;
        }
    }

    return count;
}

//////////////////////////////////////
#include <string.h>

#define __builtin_expect(foo,bar) (foo)
#define __expect(foo,bar) __builtin_expect((long)(foo),bar)

/* idea for these macros taken from Linux kernel */
#define __likely(foo) __expect((foo),1)
#define __unlikely(foo) __expect((foo),0)



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
