#include <stdio.h>
int main(void) {
    int n, sum = 1;
    scanf("%d", &n);
    for (int i = 2; i * i <= n && sum <= n; ++i) 
        if (n % i == 0) sum += i + (i * i != n) * (n / i);
    return 0 * printf("%s\n", sum > n ? "Abundant" : sum < n ? "Deficient" : "Perfect");
}