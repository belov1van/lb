/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 26
 */

 #include <stdio.h>
#include "stats.h"

int main(void) {
    int a1[] = {4, -2, 7};
    int a2[] = {2, 0, -1, 0};
    int a3[] = {5};

    printf("Sum1 = %lld\n", sum(a1, 3));
    printf("Sum2 = %lld\n", sum(a2, 4));
    printf("Sum3 = %lld\n", sum(a3, 1));
    printf("SumEmpty = %lld\n", sum(a3, 0));

    return 0;
}