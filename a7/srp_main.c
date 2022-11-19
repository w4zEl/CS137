#include <assert.h>
int shortestRepeatingPrefix(char s[]);
int main() {
    char s1[] = "hihihihi";
    assert(shortestRepeatingPrefix(s1) == 2);

    char s2[] = "aaaaa";
    assert(shortestRepeatingPrefix(s2) == 1);

    char s3[] = "qwerty";
    assert(shortestRepeatingPrefix(s3) == 6);

    char s4[] = "";
    assert(shortestRepeatingPrefix(s4) == 0);

    return 0;
}
