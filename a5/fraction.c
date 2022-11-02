#include "fraction.h"
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a < 0 ? -a : a;
}
struct fraction fractionCreate(int numerator, int denominator) {
    int div = gcd(numerator, denominator) * (numerator < 0 || !numerator && denominator < 0 ? -1 : 1);
    return (struct fraction){numerator / div, denominator / div};
}
int get_numerator(struct fraction a) {
    return a.numerator;
}
int get_denominator(struct fraction a) {
    return a.denominator;
}
struct fraction fractionAdd(struct fraction a, struct fraction b) {
    return fractionCreate(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
}
struct fraction fractionSubtract(struct fraction a, struct fraction b) {
    return fractionAdd(a, (struct fraction){-b.numerator, b.denominator});
}
struct fraction fractionMultiply(struct fraction a, struct fraction b) {
    return fractionCreate(a.numerator * b.numerator, a.denominator * b.denominator);
}
struct fraction fractionDivide(struct fraction a, struct fraction b) {
    return fractionMultiply(a, (struct fraction){b.denominator, b.numerator});
}