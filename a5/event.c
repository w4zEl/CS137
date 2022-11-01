#include "event.h"
static int getTime(struct tod t) {
    return t.hour * 60 + t.minute;
}
int freetime (struct event schedule[], int n, int hour, int min) {
    int time = hour * 60 + min;
    for (int i = 0; i < n; ++i) 
        if (getTime(schedule[i].start) <= time && time < getTime(schedule[i].end))
            return 0;
    return 1;
}