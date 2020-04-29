/*@ opt -heap @*/
// openbsd
/*@ rel_in
(and
      (= haystack$1 haystack$2)
      (= hl$1 hl$2)
      (= needle$1 needle$2)
      (= nl$1 nl$2)
      (>= haystack$1 0)
      (>= hl$1 0)
      (>= nl$1 0)
      (>= needle$1 0)
      (forall
         ((i Int))
         (= (select HEAP$1 i) (select HEAP$2 i))))
@*/
#include <stddef.h>
extern int __mark(int);
extern int memcmp (const void *, const void *, unsigned long);

void *
memmem(const void *haystack, size_t hl, const void *needle, size_t nl)
{
	const char *cur, *last;
	const char *cl = haystack;
	const char *cs = needle;

	/* a zero length needle should just return the haystack */
	/* if (nl == 0) */
	/* 	return (void *)cl; */

	/* "s" must be smaller or equal to "l" */
	if (hl < nl)
		return NULL;

	/* special case where nl == 1 */
	/* if (nl == 1) */
	/* 	return memchr(l, *cs, hl); */

	/* the last position where its possible to find "s" in "l" */
	last = cl + hl - nl;

	for (cur = cl; __mark(42) & (cur <= last); cur++)
		if (/*cur[0] == cs[0] && */memcmp(cur, cs, nl) == 0)
			return (void *)cur;

	return NULL;
}
