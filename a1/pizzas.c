#include <stdio.h>
int main(void) {
    int num_people, slices_per_pizza, slices_each;
    scanf("%d%d%d", &num_people, &slices_per_pizza, &slices_each);
    printf("%d\n", (num_people * slices_each + slices_per_pizza - 1) / slices_per_pizza);
    return 0;
}