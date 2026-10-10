/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 13
 */

#include <stdio.h>

int min_max(const int a[], int n, int *lo, int *hi) {
    if (n <= 0) {
        return 0;
    }

    int mn = a[0];
    int mx = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < mn) mn = a[i];
        if (a[i] > mx) mx = a[i];
    }

    *lo = mn;
    *hi = mx;
    return 1;
}

int main(void) {
    int a[] = {4, -2, 7};

    int lo = 99, hi = 99;
    if (min_max(a, 3, &lo, &hi)) {
        printf("n=3: Успех; lo=%d; hi=%d\n", lo, hi);
    } else {
        printf("n=3: Отказ; lo=%d; hi=%d\n", lo, hi);
    }

    lo = 99; hi = 99;
    if (min_max(a, 1, &lo, &hi)) {
        printf("n=1: Успех; lo=%d; hi=%d\n", lo, hi);
    } else {
        printf("n=1: Отказ; lo=%d; hi=%d\n", lo, hi);
    }

    lo = 99; hi = 99;
    if (min_max(a, 0, &lo, &hi)) {
        printf("n=0: Успех; lo=%d; hi=%d\n", lo, hi);
    } else {
        printf("n=0: Отказ; lo=%d; hi=%d\n", lo, hi);
    }

    return 0;
}