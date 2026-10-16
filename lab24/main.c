/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 24
 */

#include <stdio.h>

unsigned sum_digits(unsigned n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sum_digits(n / 10);
}

int main(void) {
    int value;
    if (scanf("%d", &value) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }

    if (value < 0 || value > 1000000) {
        printf("Ошибка диапазона\n");
        return 1;
    }

    printf("Сумма цифр = %u\n", sum_digits((unsigned)value));
    return 0;
}