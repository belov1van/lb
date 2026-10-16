/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 27
 */

#include <assert.h>
#include <stdio.h>

int first_negative(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int at_start[] = {-2, 4, 0, 0};
    int at_end[]   = {3, 1, 2, -1};
    int several[]  = {-1, -2, -3, 5};
    int no_neg[]   = {0, 3, 7};
    int with_zero[] = {0, 0, 1};

    assert(first_negative(at_start, 4) == 0);
    assert(first_negative(at_end, 4) == 3);
    assert(first_negative(several, 4) == 0);
    assert(first_negative(no_neg, 3) == -1);
    assert(first_negative(no_neg, 0) == -1);
    assert(first_negative(with_zero, 3) == -1);

    puts("All tests passed");
    return 0;
}

/*
int main(void) {
    int at_start[] = {-2, 4, 0, 0};
    int at_end[]   = {3, 1, 2, -1};
    int several[]  = {-1, -2, -3, 5};
    int no_neg[]   = {0, 3, 7};
    int with_zero[] = {0, 0, 1};

    printf("at_start:  %d (ожидается 0)\n",  first_negative(at_start, 4));
    printf("at_end:    %d (ожидается 3)\n",  first_negative(at_end, 4));
    printf("several:   %d (ожидается 0)\n",  first_negative(several, 4));
    printf("no_neg:    %d (ожидается -1)\n", first_negative(no_neg, 3));
    printf("n=0:       %d (ожидается -1)\n", first_negative(no_neg, 0));
    printf("with_zero: %d (ожидается -1)\n", first_negative(with_zero, 3));

    return 0;
}

output: 

at_start:  0 (ожидается 0)
at_end:    3 (ожидается 3)
several:   0 (ожидается 0)
no_neg:    -1 (ожидается -1)
n=0:       -1 (ожидается -1)
with_zero: -1 (ожидается -1)

*/