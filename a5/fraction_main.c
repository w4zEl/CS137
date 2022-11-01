#include <assert.h>
#include "fraction.h"

int main(void) {
    struct fraction a, b, c, r, zero;
    a = fractionCreate(40, 26);
    assert(20 == get_numerator(a));
    assert(13 == get_denominator(a));
    b = fractionCreate(18, 19);
    assert(18 == get_numerator(b));
    assert(19 == get_denominator(b));
    c = fractionCreate(360, 540);
    assert(2 == get_numerator(c));
    assert(3 == get_denominator(c));
    zero = fractionCreate(0, 10);
    assert(0 == get_numerator(zero));
    assert(1 == get_denominator(zero));

    r = fractionAdd(a, b);
    assert(614 == get_numerator(r));
    assert(247 == get_denominator(r));

    r = fractionSubtract(c, c);
    assert(0 == get_numerator(r));
    assert(1 == get_denominator(r));

    r = fractionMultiply(a, b);
    assert(360 == get_numerator(r));
    assert(247 == get_denominator(r));

    r = fractionDivide(c, a);
    assert(13 == get_numerator(r));
    assert(30 == get_denominator(r));
    r = fractionDivide(c, c);
    assert(1 == get_numerator(r));
    assert(1 == get_denominator(r));

    r = fractionCreate(-10, -2);
    assert(5 == get_numerator(r));
    assert(1 == get_denominator(r));
    r = fractionCreate(-2, 14);
    assert(1 == get_numerator(r));
    assert(-7 == get_denominator(r));
    a = fractionCreate(1, 3);
    b = fractionCreate(3, 1);
    r = fractionSubtract(a, b);
    assert(8 == get_numerator(r));
    assert(-3 == get_denominator(r));
    return 0;
}
