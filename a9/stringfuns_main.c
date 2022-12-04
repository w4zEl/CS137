#include <stdio.h>
#include <string.h>
#include <assert.h>

void reduce(void* src, size_t n, size_t src_bytes,
    void* dest, void (*f)(void*, void*)) {
    if (n == 1) {
        f(src, dest);
        return;
    }
    reduce((char*)src + src_bytes, n - 1, src_bytes, dest, f);
    f(src, dest);
}

void reverseConcatenate(void* lhs, void* rhs);
void concatenate(void* lhs, void* rhs);

int main(void) {
    int n = 10;
    char* words[] = { "The", "Quick", "Brown", "", "Fox", "Jumps", "Over", "The", "Lazy", "Dog" };
    char result[] = "TheQuickBrownFoxJumpsOverTheLazyDog";
    char backwards_result[] = "DogLazyTheOverJumpsFoxBrownQuickThe";

    char answer[1000];
    answer[0] = '\0';
    reduce(words, n, sizeof(char*), answer, reverseConcatenate);
    puts(answer);
    assert(!strcmp(answer, backwards_result));

    answer[0] = '\0';
    reduce(words, n, sizeof(char*), answer, concatenate);
    assert(!strcmp(answer, result));
    puts(answer);
    return 0;
}
