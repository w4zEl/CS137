typedef struct Point {
    int x;
    int y;
} point;
typedef struct Rectangle {
    point bottomLeft;
    int width;
    int height;
} rectangle;
static int max(int a, int b) {
    return a > b ? a : b;
}
static int min(int a, int b) {
    return a < b ? a : b;
}
rectangle intersection(rectangle rects[], int n) {
    rectangle res = rects[0];
    for (int i = 1; i < n; ++i) {
        point bot = { max(res.bottomLeft.x, rects[i].bottomLeft.x), max(res.bottomLeft.y, rects[i].bottomLeft.y) };
        res = (rectangle) { bot, min(res.bottomLeft.x + res.width, rects[i].bottomLeft.x + rects[i].width) - bot.x,
            min(res.bottomLeft.y + res.height, rects[i].bottomLeft.y + rects[i].height) - bot.y };
        if (res.width < 0 || res.height < 0) return (rectangle) { 0 };
    }
    return res;
}