#include <string.h>
#include <stdlib.h>
char* next(char *s) { return *s && *s != ' ' ? next(s + 1) : s; }
char* merge(char* s1, char* s2) {
    size_t len1 = strlen(s1), len2 = strlen(s2);
    char *res = calloc(len1 + len2 + 2, 1), *t, *b = "";
    #define add(s) if ((t = next(s)) - s) strncat(strcat(res, b), s, t - s), *(s = t) && ++s, b = " "
    while (*s1 || *s2) { add(s1); add(s2); }
    return res;
}