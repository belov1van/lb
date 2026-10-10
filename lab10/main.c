/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 10
 */


#include <stdio.h>

int min2(int a, int b) {
    if (a < b) return a;
    return b;
}

int max2(int a, int b) {
    if (a > b) return a;
    return b;
}

int range3(int x, int y, int z) {
    int mn = min2(min2(x, y), z);
    int mx = max2(max2(x, y), z);
    return mx - mn;
}

int main(void) {
    int x, y, z;

    printf("Введите три числа (-1000..1000): ");
    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        printf("Ошибка ввода\n");
        return 1;
    }

    if (x < -1000 || x > 1000 ||
        y < -1000 || y > 1000 ||
        z < -1000 || z > 1000) {
        printf("Ошибка диапазона\n");
        return 1;
    }

    printf("Range = %d\n", range3(x, y, z));

    return 0;
}