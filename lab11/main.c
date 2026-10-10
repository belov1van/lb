/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 11
 */

#include <stdio.h>

int count_above(const int a[], int n, int limit) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > limit) {
            count++;
        }
    }
    return count;
}

void print_array(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}

int main(void) {
    int a[] = {4, -2, 7, 0};
    int n = (int)(sizeof a / sizeof a[0]);

    printf("Массив: ");
    print_array(a, n);

    printf("n=%d, limit=0  -> %d\n", n, count_above(a, n, 0));
    printf("n=%d, limit=7  -> %d\n", n, count_above(a, n, 7));
    printf("n=2, limit=-3  -> %d\n", count_above(a, 2, -3));
    printf("n=0, limit=0   -> %d\n", count_above(a, 0, 0));

    printf("Собственный тест: n=%d, limit=4 -> %d\n", n, count_above(a, n, 4));

    return 0;
}