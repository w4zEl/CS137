#include <stdbool.h>
#define ABS(x) ((x)<0?(-x):(x))
bool divide(int a, int b) {
    return b == 0 || ABS(b) >= ABS(a) && divide(a, ABS(b) - ABS(a));
}
int IntegerDivision(int a, int b) {
    return a < b ? 0 : 1 + IntegerDivision(a - b, b);
}