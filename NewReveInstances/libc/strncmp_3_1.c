/* openbsd */
#include <stddef.h>

/////////////////////////////////////////////////////
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HEADER_MAX          256

static char macrofile[] = "/tmp/isomac.XXXXXX";

/* ISO C header names including Amendment 1 (without ".h" suffix).  */
static char *header[] =
{
  "assert", "ctype", "errno", "float", "iso646", "limits", "locale",
  "math", "setjmp", "signal", "stdarg", "stddef", "stdio", "stdlib",
  "string", "time", "wchar", "wctype"
};

/* Macros with these prefixes are considered okay.  */
static char *prefix[] =
{
  "_", "E", "is", "str", "mem", "SIG", "FLT_", "DBL_", "LDBL_",
  "LC_", "wmem", "wcs"
};

/* Macros with these suffixes are considered okay.  Will not work for
   parametrized macros with arguments.  */
static char *suffix[] =
{
  "_MAX", "_MIN"
};

/* These macros are considered okay. In fact, these are just more prefixes.  */
static char *macros[] =
{
  "BUFSIZ", "CHAR_BIT", "CHAR_MAX", "CHAR_MIN", "CLOCKS_PER_SEC",
  "DBL_DIG", "DBL_EPSILON", "DBL_MANT_DIG", "DBL_MAX",
  "DBL_MAX_10_EXP", "DBL_MAX_EXP", "DBL_MIN", "DBL_MIN_10_EXP",
  "DBL_MIN_EXP", "EDOM", "EILSEQ", "EOF", "ERANGE", "EXIT_FAILURE",
  "EXIT_SUCCESS", "FILENAME_MAX", "FLT_DIG", "FLT_EPSILON",
  "FLT_MANT_DIG", "FLT_MAX", "FLT_MAX_10_EXP", "FLT_MAX_EXP",
  "FLT_MIN", "FLT_MIN_10_EXP", "FLT_MIN_EXP", "FLT_RADIX",
  "FLT_ROUNDS", "FOPEN_MAX", "HUGE_VAL", "INT_MAX", "INT_MIN",
  "LC_ALL", "LC_COLLATE", "LC_CTYPE", "LC_MONETARY", "LC_NUMERIC",
  "LC_TIME", "LDBL_DIG", "LDBL_EPSILON", "LDBL_MANT_DIG", "LDBL_MAX",
  "LDBL_MAX_10_EXP", "LDBL_MAX_EXP", "LDBL_MIN", "LDBL_MIN_10_EXP",
  "LDBL_MIN_EXP", "LONG_MAX", "LONG_MIN", "L_tmpnam", "MB_CUR_MAX",
  "MB_LEN_MAX", "NDEBUG", "NULL", "RAND_MAX", "SCHAR_MAX",
  "SCHAR_MIN", "SEEK_CUR", "SEEK_END", "SEEK_SET", "SHRT_MAX",
  "SHRT_MIN", "SIGABRT", "SIGFPE", "SIGILL", "SIGINT", "SIGSEGV",
  "SIGTERM", "SIG_DFL", "SIG_ERR", "SIG_IGN", "TMP_MAX", "UCHAR_MAX",
  "UINT_MAX", "ULONG_MAX", "USHRT_MAX", "WCHAR_MAX", "WCHAR_MIN",
  "WEOF", "_IOFBF", "_IOLBF", "_IONBF", "abort", "abs", "acos",
  "acosf", "acosl", "and", "and_eq", "asctime", "asin", "asinf",
  "asinl", "assert", "atan", "atan2", "atan2f", "atan2l", "atanf",
  "atanl", "atexit", "atof", "atoi", "atol", "bitand", "bitor",
  "bsearch", "btowc", "calloc", "ceil", "ceilf", "ceill", "clearerr",
  "clock", "clock_t", "compl", "cos", "cosf", "cosh", "coshf",
  "coshl", "cosl", "ctime", "difftime", "div", "div_t", "errno",
  "exit", "exp", "expf", "expl", "fabs", "fabsf", "fabsl", "fclose",
  "feof", "ferror", "fflush", "fgetc", "fgetpos", "fgets", "fgetwc",
  "fgetws", "floor", "floorf", "floorl", "fmod", "fmodf", "fmodl",
  "fopen", "fprintf", "fputc", "fputs", "fputwc", "fputws", "fread",
  "free", "freopen", "frexp", "frexpf", "frexpl", "fscanf", "fseek",
  "fsetpos", "ftell", "fwide", "fwprintf", "fwrite", "fwscanf",
  "getc", "getchar", "getenv", "gets", "getwc", "getwchar", "gmtime",
  "isalnum", "isalpha", "iscntrl", "isdigit", "isgraph", "islower",
  "isprint", "ispunct", "isspace", "isupper", "iswalnum", "iswalpha",
  "iswcntrl", "iswctype", "iswdigit", "iswgraph", "iswlower",
  "iswprint", "iswpunct", "iswspace", "iswupper", "iswxdigit",
  "isxdigit", "labs", "ldexp", "ldexpf", "ldexpl", "ldiv", "ldiv_t",
  "localeconv", "localtime", "log", "log10", "log10f", "log10l",
  "logf", "logl", "longjmp", "malloc", "mblen", "mbrlen", "mbrtowc",
  "mbsinit", "mbsrtowcs", "mbstate_t", "mbstowcs", "mbtowc", "memchr",
  "memcmp", "memcpy", "memmove", "memset", "mktime", "modf", "modff",
  "modfl", "not", "not_eq", "offsetof", "or", "or_eq", "perror",
  "pow", "powf", "powl", "printf", "ptrdiff_t", "putc", "putchar",
  "puts", "putwc", "putwchar", "qsort", "raise", "rand", "realloc",
  "remove", "rename", "rewind", "scanf", "setbuf", "setjmp",
  "setlocale", "setvbuf", "sig_atomic_t", "signal", "sin", "sinf",
  "sinh", "sinhf", "sinhl", "sinl", "size_t", "sprintf", "sqrt",
  "sqrtf", "sqrtl", "srand", "sscanf", "stderr", "stdin", "stdout",
  "strcat", "strchr", "strcmp", "strcoll", "strcpy", "strcspn",
  "strerror", "strftime", "strlen", "strncat", "strncmp", "strncpy",
  "strpbrk", "strrchr", "strspn", "strstr", "strtod", "strtok",
  "strtol", "strtoul", "strxfrm", "swprintf", "swscanf", "system",
  "tan", "tanf", "tanh", "tanhf", "tanhl", "tanl", "time", "time_t",
  "tmpfile", "tmpnam", "tolower", "toupper", "towctrans", "towlower",
  "towupper", "ungetc", "ungetwc", "va_arg", "va_copy", "va_end", "va_start",
  "vfprintf", "vfwprintf", "vprintf", "vsprintf", "vswprintf",
  "vwprintf", "wchar_t", "wcrtomb", "wcscat", "wcschr", "wcscmp",
  "wcscoll", "wcscpy", "wcscspn", "wcsftime", "wcslen", "wcsncat",
  "wcsncmp", "wcsncpy", "wcspbrk", "wcsrchr", "wcsrtombs", "wcsspn",
  "wcsstr", "wcstod", "wcstok", "wcstol", "wcstombs", "wcstoul",
  "wcsxfrm", "wctob", "wctomb", "wctrans", "wctrans_t", "wctype",
  "wctype_t", "wint_t", "wmemchr", "wmemcmp", "wmemcpy", "wmemmove",
  "wmemset", "wprintf", "wscanf", "xor", "xor_eq"
};

#define NUMBER_OF_HEADERS              (sizeof header / sizeof *header)
#define NUMBER_OF_PREFIXES             (sizeof prefix / sizeof *prefix)
#define NUMBER_OF_SUFFIXES             (sizeof suffix / sizeof *suffix)
#define NUMBER_OF_MACROS               (sizeof macros / sizeof *macros)


/* Format string to build command to invoke compiler.  */
static const char fmt[] = "\
echo \"#include <%s>\" |\
%s -E -dM -ansi -pedantic %s -D_LIBC -D_ISOMAC \
-DIN_MODULE=MODULE_extramodules -I. \
-isystem `%s --print-prog-name=include` - 2> /dev/null > %s";


/* The compiler we use (given on the command line).  */
char *CC;
/* The -I parameters for CC to find all headers.  */
char *INC;


static int
check_header (const char *file_name, const char **except)
{
  char line[BUFSIZ], *command;
  FILE *input;
  int result = 0;

  command = malloc (sizeof fmt + strlen (file_name) + 2 * strlen (CC)
		    + strlen (INC) + strlen (macrofile));

  if (command == NULL)
    {
      puts ("No more memory.");
      exit (1);
    }

  puts (file_name);
  sprintf (command, fmt, file_name, CC, INC, CC, macrofile);

  if (system (command))
    {
      puts ("system() returned nonzero");
      result = 1;
    }
  free (command);
  input = fopen (macrofile, "r");

  if (input == NULL)
    {
      printf ("Could not read %s: ", macrofile);
      perror (NULL);
      return 1;
    }

  while (fgets (line, sizeof line, input) != NULL)
    {
      int i, okay = 0;
      size_t endmac;
      const char **cpp;
      if (strlen (line) < 9 || line[7] != ' ')
	{ /* "#define A" */
	  printf ("Malformed input, expected '#define MACRO'\ngot '%s'\n",
		  line);
	  result = 1;
	  continue;
	}
      for (i = 0; i < NUMBER_OF_PREFIXES; ++i)
	{
	  if (!strncmp (line+8, prefix[i], strlen (prefix[i]))) {
	    ++okay;
	    break;
	  }
	}
      if (okay)
	continue;
      for (i = 0; i < NUMBER_OF_MACROS; ++i)
	{
	  if (!strncmp (line + 8, macros[i], strlen (macros[i])))
	    {
	      ++okay;
	      break;
	    }
	}
      if (okay)
	continue;
      /* Find next char after the macro identifier; this can be either
	 a space or an open parenthesis.  */
      endmac = strcspn (line + 8, " (");
      if (line[8+endmac] == '\0')
	{
	  printf ("malformed input, expected '#define MACRO VALUE'\n"
		  "got '%s'\n", line);
	  result = 1;
	  continue;
	}
      for (i = 0; i < NUMBER_OF_SUFFIXES; ++i)
	{
	  size_t len = strlen (suffix[i]);
	  if (!strncmp (line + 8 + endmac - len, suffix[i], len))
	    {
	      ++okay;
	      break;
	    }
	}
      if (okay)
	continue;
      if (except != NULL)
	for (cpp = except; *cpp != NULL; ++cpp)
	  {
	    size_t len = strlen (*cpp);
	    if (!strncmp (line + 8, *cpp, len) && isspace (line[8 + len]))
	      {
		++okay;
		break;
	      }
	  }
      if (!okay)
	{
	  fputs (line, stdout);
	  result = 2;
	}
    }
  fclose (input);

  return result;
}

/////////////////////////////////////////////////////


extern int __mark(int);

int strncmp(const char *s1, const char *s2, size_t n) {

    if (n == 0)
        return (0);
    do {
        if (*s1 != *s2++)
            return (*(unsigned char *)s1 - *(unsigned char *)--s2);
        if (*s1++ == 0)
            break;
    } while (__mark(42) & (--n != 0));
    return (0);
}
