#include <stdio.h>
static int stars_helper(long n) {
    return n ? n % 10 == stars_helper(n / 10) && printf("*"), printf("%ld", n % 10), n % 10 : -1;
}
void stars(long int n) {
    stars_helper(n);
}