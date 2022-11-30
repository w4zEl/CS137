#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool newSearch(int arr[], int len, int x);

int main(void) {
    int a[1] = { 14 };
    assert(!newSearch(a, 1, 10));
    printf("\n\n");
    assert(newSearch(a, 1, 14));
    printf("\n\n");
    int b[13] = { 1, 4, 5, 7, 12, 23, 44, 67, 89, 100, 120, 121, 122 };
    assert(!newSearch(b, 13, 0));
    printf("\n\n");
    assert(!newSearch(b, 13, 150));
    printf("\n\n");
    assert(newSearch(b, 13, 4));
    printf("\n\n");
    assert(newSearch(b, 13, 121));
    printf("\n\n");
    assert(newSearch(b, 13, 23));
    printf("\n\n");
    int c[20] = { -10, -4, 5, 7, 12, 23, 44, 67, 89, 100, 120, 121, 122, 200, 210, 222, 300, 301, 303, 500 };
    assert(!newSearch(c, 20, 55));
    printf("\n\n");
    assert(newSearch(c, 20, 12));
    printf("\n\n");
    return 0;
}
