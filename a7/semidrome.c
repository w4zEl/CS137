#include <stdbool.h>
bool is_palindrome(char* start, char *end) { return start >= end || *start == *end && is_palindrome(start + 1, end - 1); }
bool is_semidrome(char *s) {
    for (char *p = s; *p; ++p) if (p - s && is_palindrome(s, p) && (!p[1] || is_semidrome(p + 1))) return true;
    return false;
}