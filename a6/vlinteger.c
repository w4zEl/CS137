#include "vlinteger.h"
#include <stdlib.h>
#include <stdio.h>
struct linteger* vlintegerCreate(void) {
    struct linteger* t1 = malloc(sizeof *t1);
    t1->arr = NULL;
    t1->length = 0;
    return t1;
}
void vlintegerDestroy(struct linteger* v) {
    if (v) free(v->arr), free(v);
}
void vlintegerRead(struct linteger* t1) {
    for (int x; scanf("%d", &x);) {
        t1->arr = realloc(t1->arr, ++t1->length * sizeof(int));
        t1->arr[t1->length - 1] = x;
    }
}
void vlintegerPrint(struct linteger* t1) {
    printf("length=%d\n", t1->length);
    for (int i = 0; i < t1->length; ++i) printf("%d", t1->arr[i]);
    printf("\n");
}
static struct linteger* normalize(int *d, int len) {
    struct linteger* li = vlintegerCreate();
    li->length = len - !*d;
    if (!*d) for (int i = 1; i < len; ++i) d[i - 1] = d[i];
    li->arr = realloc(d, li->length * sizeof(int));
    return li;
}
struct linteger* vlintegerAdd(struct linteger* t1, struct linteger* t2) {
    int j = t1->length, k = t2->length, len = (j > k ? j : k) + 1, i = len, *s = malloc(len * sizeof *s), carry = 0;
    while (i--) {
        int curr = (j ? t1->arr[--j] : 0) + (k ? t2->arr[--k] : 0) + carry;
        s[i] = curr % 10;
        carry = curr / 10;
    }
    return normalize(s, len);
}
struct linteger* vlintegerMult(struct linteger* t1, struct linteger* t2) {
    int len = t1->length + t2->length, *p = calloc(len, sizeof *p);
    for (int i = t1->length; i--;) {
        int carry = 0;
        for (int j = t2->length; j--;) {
            int curr = t1->arr[i] * t2->arr[j] + p[i + j + 1] + carry;
            p[i + j + 1] = curr % 10;
            carry = curr / 10;
        }
        p[i] += carry;
    }
    return normalize(p, len);
}