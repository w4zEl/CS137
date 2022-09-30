#include "functions.h"
static int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return 0;
    return 1;
}
int isSophieGermainPrime(int n) {
    return isPrime(n) && isPrime(n * 2 + 1);
}
static int baseConvert(int num, int from, int to) {
    int res = 0;
    for (int pow = 1; num; pow *= from, num /= to)
        res += num % to * pow;
    return res;
}
int base2nat(int bs, int num) {
    return baseConvert(num, bs, 10);
}
int nat2base(int bs, int num) {
    return baseConvert(num, 10, bs);
}