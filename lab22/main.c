/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 22
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        printf("Ошибка размера\n");
        return 1;
    }

    int *a = malloc((size_t)n * sizeof *a);
    if (a == NULL) {
        printf("Ошибка памяти\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Ошибка ввода\n");
            free(a);
            return 1;
        }
        if (a[i] < -1000 || a[i] > 1000) {
            printf("Ошибка значения\n");
            free(a);
            return 1;
        }
    }

    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }

    printf("Min = %d\n", min);

    free(a);
    a = NULL;
    return 0;
}