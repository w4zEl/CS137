#include <stdbool.h>
#include <stdlib.h>
void sort(void* arr, int n, size_t elemsize, bool (*compare)(const void* a, const void* b), void (*swap)(void* a, void* b)) {
    #define get(i) (char*) arr + i * elemsize
    for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) if (compare(get(j), get(i))) swap(get(i), get(j));
}