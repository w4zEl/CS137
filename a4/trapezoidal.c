#include <math.h>
double calcArea(double f(double), double a, double b, int n) {
    double dx = (b - a) / n, area = 0;
    for (int i = 0; i < n; ++i)
        area += (f(a + dx * i) + f(a + dx * (i + 1))) * dx / 2;
    return area;
}
double trapezoidal(double (*f)(double), double a, double b, double epsilon, int n) {
    double prev = calcArea(f, a, b, n), curr;
    while (fabs((curr = calcArea(f, a, b, n *= 2)) - prev) > epsilon)
        prev = curr;
    return curr;
}