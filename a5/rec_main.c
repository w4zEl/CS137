#include <assert.h>
typedef struct Point {
    int x;
    int y;
} point;
typedef struct Rectangle {
    point bottomLeft;
    int width;
    int height;
} rectangle;
rectangle intersection(rectangle rects[], int n);
int main() {
    rectangle result;
    rectangle r = {{2, 6}, 3, 4};
    rectangle s = {{0, 7}, 7, 1};
    rectangle t = {{3, 5}, 1, 6};
    rectangle u = {{5, 6}, 3, 4};

    // Test 1
    rectangle rects1[2] = {r, s};
    result = intersection(rects1, 2);
    assert(result.bottomLeft.x == 2);
    assert(result.bottomLeft.y == 7);
    assert(result.width == 3);
    assert(result.height == 1);

    // Test 2
    rectangle rects2[3] = {r, s, t};
    result = intersection(rects2, 3);
    assert(result.bottomLeft.x == 3);
    assert(result.bottomLeft.y == 7);
    assert(result.width == 1);
    assert(result.height == 1);

    // Test 3
    rectangle rects3[4] = {r, s, t, u};
    result = intersection(rects3, 4);
    assert(result.bottomLeft.x == 0);
    assert(result.bottomLeft.y == 0);
    assert(result.width == 0);
    assert(result.height == 0);

    return 0;
}