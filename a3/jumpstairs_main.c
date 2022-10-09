#include <assert.h>
int jump_stair_v1(int n);
int jump_stair_v2(int n);
int jump_stair_v3(int n);
int main(void) {
    assert(1==jump_stair_v1(1));
    assert(1==jump_stair_v2(1));
    assert(0==jump_stair_v3(1));
    assert(2==jump_stair_v1(2));
    assert(2==jump_stair_v2(2));
    assert(0==jump_stair_v3(2));
    assert(13==jump_stair_v1(6));
    assert(2==jump_stair_v2(6));
    assert(1==jump_stair_v3(6));
    assert(21==jump_stair_v1(7));
    assert(3==jump_stair_v2(7));
    assert(0==jump_stair_v3(7));
    assert(55==jump_stair_v1(9));
    assert(3==jump_stair_v2(9));
    assert(1==jump_stair_v3(9));
}