#include <assert.h>
#include <stdbool.h>
bool divide(int, int);
int IntegerDivision(int, int);
int main(void) {
    assert(divide(2,10));
    assert(divide(2,-10));
    assert(!divide(7,22));
    assert(IntegerDivision(10,5)==2);
    assert(IntegerDivision(151,5)==30);
}