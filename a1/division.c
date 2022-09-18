#include <stdio.h>
int main(void) {
    int num, denom, quotient;
    scanf("%d%d", &num, &denom);
    quotient = num / denom;
    if (num % denom) quotient += num < 0 == denom < 0 ? 1: -1;
    printf("%d\n", quotient);
    return 0;
}