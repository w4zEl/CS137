#include <string.h>
int shortestRepeatingPrefix(char s[]) {
    int len = strlen(s);
    for (int i = 1; i <= len; i++) 
        if (len % i == 0) {
            int valid = 1;
            for (int j = 0; j < len; j++) valid &= s[j] == s[j % i];
            if (valid) return i;
        }
    return 0;
}