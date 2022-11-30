#include <stdbool.h>
#include <stdio.h>
bool newSearch(int arr[], int len, int x) {
    int l = 0, r = len - 1;
    printf("start with the range %d to %d\n", arr[l], arr[r]);
    while (x >= arr[l] && x <= arr[r]) {
        int pos = r - l ? l + 1. * (x - arr[l]) / (arr[r] - arr[l]) * (r - l) : l;
        if (arr[pos] == x) return printf("%d was found in position %d\n", x, pos);
        else if (x < arr[pos]) r = pos - 1;
        else l = pos + 1;
        printf("move to search in the range between %d and %d\n", arr[l], arr[r]);
    }
    return !printf("%d not in the range between %d and %d\n", x, arr[l], arr[r]);
}