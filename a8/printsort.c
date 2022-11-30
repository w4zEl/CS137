#include <stdio.h>
void printsorted(char* word, int len) {
    int freq[26] = {0};
    for (char *w = word; *w; ++w) *w < 97 | *w > 'z' || ++freq[*w - 97];
    for (int i = len; i; i--) for (int c = 0; c < 26; c++) if(freq[c] == i) for (int j = 0; j < i; ++j) putchar(c + 97);
    puts("");
}