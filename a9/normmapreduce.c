#include <math.h>
typedef struct Vector {
    double x, y, z;
} Vector;
void EuclideanNorm(void *src, void *dest) {
    Vector* vec = src;
    *(double*)dest = hypot(hypot(vec->x, vec->y), vec->z);
}
void sum(void *src, void *dest) {
    *(double*) dest += *(double*) src;
}