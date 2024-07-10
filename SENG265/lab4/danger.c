#include <stdio.h>

#define MAX_NUMS  5

void rogue(int *numbers, int num, int innocent, int really_innocent)
{
    int i;

    for (i = -2; i <= num; i++) {
	printf("\ni = %d\n", i);
	printf("before edit: %d\n", numbers[i]);
        numbers[i] = 111 * i + 11;
	printf("after edit: %d\n", numbers[i]);
	printf("%d %d\n", innocent, really_innocent);
    }
printf("hi\n");
}


int main() {
    int innocent = 123;
    int nums[MAX_NUMS] = {1, 2, 3, 4, 5};
    int really_innocent = 456;
    int i;

    printf("%d %d\n", innocent, really_innocent);
    for (i = 0; i < MAX_NUMS; i++) {
        printf("%d: %d\n", i, nums[i]);
    }

    rogue(nums, MAX_NUMS, innocent, really_innocent);
printf("hi2\n");
    printf("----------------\n");
    printf("%d %d\n", innocent, really_innocent);
    for (i = 0; i < MAX_NUMS; i++) {
        printf("%d: %d\n", i, nums[i]);
    }
}
/*the program isn't getting to this point, but I think after the line it would print
"123 456
11
122
233
344
455"
*/
