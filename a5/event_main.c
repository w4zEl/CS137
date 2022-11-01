#include <assert.h>
#include "event.h"

int main(void) {
    struct event schedule[] = {{{9, 45}, {9, 55}}, {{13, 0}, {14, 20}}, {{15, 0}, {16, 30}}};
    assert(freetime(schedule, 3, 10, 0));
    assert(!freetime(schedule, 3, 9, 50));
    return 0;
}