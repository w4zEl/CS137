#include <string.h>
void reverseConcatenate(void* lhs, void* rhs) {
    strcat(rhs, *(char**)lhs);
}
void concatenate(void* lhs, void* rhs) {
    char *str1 = *(char**)lhs, *str2 = rhs;
    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = len2; ~i; i--) str2[i + len1] = str2[i];
    for (int i = len1; i--;) str2[i] = str1[i];
}