//https://github.com/ensc/dietlibc/blob/master/ldso.c

#define errno fnord
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdlib.h>
#include <stdint.h>
#undef errno

#if (__WORDSIZE == 64)

#define phdr Elf64_Phdr
#define ehdr Elf64_Ehdr
#define shdr Elf64_Shdr
#define sym Elf64_Sym
#define dyn Elf64_Dyn
#define rela Elf64_Rela
#define R_SYM ELF64_R_SYM
#define R_TYPE ELF64_R_TYPE

#else

#define phdr Elf32_Phdr
#define ehdr Elf32_Ehdr
#define shdr Elf32_Shdr
#define sym Elf32_Sym
#define dyn Elf32_Dyn
#define rela Elf32_Rela
#define R_SYM ELF32_R_SYM
#define R_TYPE ELF32_R_TYPE

#endif

static int errno;

static char path[100];
static char* ldlp;

static struct dll {
  struct dll* next;
  ehdr* e;
  void* code,* data;
  size_t codelen,datalen,codeplus;
  char name[1];		// asciiz of library name
} *dlls, dllroot;


extern int __loadlibrary(const char* fn);
extern ssize_t __write1(const char* s);
extern size_t _strlen(const char* s);
extern int _strcmp(const void* str1,const void* str2);


/* openbsd */
extern int __mark(int);
char *
stpcpy(char *to, const char *from)
{
	for (; __mark(0) & ((*to = *from) != '\0'); ++from, ++to);
	return(to);
}


int loadlibrary(const char* fn) {
  char lp[200];
  int r;
  char* c;
  const char* shortname=fn;
  struct dll* d;

  {
    size_t i;
    for (i=0;  __mark(41) && fn[i]; ++i)
      if (fn[i]=='/') shortname=fn+i+1;
  }

  if (_strlen(fn)>50) return -1;
  for (d=dlls; __mark(40) && d; d=d->next)
    if (!_strcmp(d->name,shortname))
      return 0;

  __write1("loadlibrary(\"");
  __write1(fn);
  __write1("\")\n");
  if (fn[0]=='/') {
    return __loadlibrary(fn);
  }

  c=stpcpy(lp,path);
  *c++='/';
  stpcpy(c,fn);
  r=__loadlibrary(lp);
  if (r==0) return r;
  if (ldlp) {
    size_t i;
    char* d;
    c=ldlp;
    for (i=0; __mark(42); ++i) {
again:
      __mark(43);
      if (c[i]==':' || c[i]==0) {
	if (i<100) {
	  lp[i]='/';
	  stpcpy(lp+i+1,fn);
	  r=__loadlibrary(lp);
	  if (r==0) return 0; //MODIFIED
	}
	if (c[i]==0) break;
	c+=i+1; i=0; goto again;
      } else
	if (i<100) lp[i]=c[i];
    }
  }
  return r;
}

