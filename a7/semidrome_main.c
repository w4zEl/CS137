#include <stdbool.h>
#include <assert.h>

bool is_semidrome(char* s);

int main(void) {
    assert(is_semidrome("popeye"));
    assert(is_semidrome("racecar"));
    assert(!is_semidrome("aab"));
    assert(!is_semidrome(""));
    return 0;
}
