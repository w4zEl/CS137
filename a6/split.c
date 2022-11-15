#include <stdlib.h>
int ** split(int a[], int n, int p, int *len1, int *len2) {
    for (int i = *len2 = 0; i < n; i++) *len2 += a[i] > p;
    int *down = malloc((*len1 = n - *len2) * sizeof *down), *up = malloc(*len2 * sizeof *up), **res = malloc(2 * sizeof *res);
    *res = down, res[1] = up;
    for (int i = 0; i < n; i++) a[i] > p ? (*up++ = a[i]) : (*down++ = a[i]);
    return res;
}