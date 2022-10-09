int jump_stair_v1(int n) {
    return n < 2 ? 1 : jump_stair_v1(n - 1) + jump_stair_v1(n - 2);
}
int jump_stair_v2(int n) {
    return n < 0 ? 0 : n < 2 ? 1 : 4 % n == 0 ? 2 : jump_stair_v2(n - 3) + jump_stair_v2(n - 6);
}
int jump_stair_v3(int n) {
    return n < 0 ? 0 : n == 0 ? 1 : jump_stair_v3(n - 6) + jump_stair_v3(n - 9);
}