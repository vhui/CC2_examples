/* dietlibc */
extern int __mark(int);
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

//////////////////////////https://github.com/google/boringssl/blob/master/crypto/asn1/a_mbstr.c
/*
#include <openssl/asn1.h>

#include <limits.h>
#include <string.h>

#include <openssl/bytestring.h>
#include <openssl/err.h>
#include <openssl/mem.h>

#include "asn1_locl.h"
#include "../bytestring/internal.h"

static int is_printable(uint32_t value);
*/
#include <stdint.h>

/* Return 1 if the character is permitted in a PrintableString */
int is_printable(uint32_t value) //static
{
    int ch;
    if (value > 0x7f)
        return 0;
    ch = (int)value;
    /*
     * Note: we can't use 'isalnum' because certain accented characters may
     * count as alphanumeric in some environments.
     */
    if ((ch >= 'a') && (ch <= 'z'))
        return 1;
    if ((ch >= 'A') && (ch <= 'Z'))
        return 1;
    if ((ch >= '0') && (ch <= '9'))
        return 1;
    if ((ch == ' ') || strchr("'()+,-./:=?", ch))
        return 1;
    return 0;
}
