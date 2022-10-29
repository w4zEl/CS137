#include <stdbool.h>
bool canComplete(int i, int arr[], int len) {
    if (i == len - 1) return true;
    for (int j = 1; j <= arr[i] && i + j < len; ++j)
        if (canComplete(i + j, arr, len))
            return true;
    return false;
}