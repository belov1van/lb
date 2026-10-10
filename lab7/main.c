/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 7
 */

#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    int a[MAX_SIZE];
    int b[MAX_SIZE];
    int n;

    printf("Введите n (1..100): ");
    if (scanf("%d", &n) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }

    if (n < 1 || n > MAX_SIZE) {
        printf("Ошибка размера\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("a[%d]: ", i);
        if (scanf("%d", &a[i]) != 1) {
            printf("Ошибка ввода\n");
            return 1;
        }
        if (a[i] < -1000 || a[i] > 1000) {
            printf("Ошибка значения\n");
            return 1;
        }
    }

    int replacements = 0;
    long long sum_b = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            b[i] = 0;
            replacements++;
        } else {
            b[i] = a[i];
        }
        sum_b += b[i];
    }

    printf("Исходный массив a:");
    for (int i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    printf("Массив b:");
    for (int i = 0; i < n; i++) {
        printf(" %d", b[i]);
    }
    printf("\n");

    printf("Количество замен = %d\n", replacements);
    printf("Сумма элементов b = %lld\n", sum_b);

    return 0;
}