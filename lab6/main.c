/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 6
 */

#include <stdio.h>

int main(void) {
    int h;
    int w;

    printf("Введите высоту и ширину прямоугольника: ");

    if (scanf("%d %d", &h, &w) != 2) {
        printf("Input error\n");
        return 1;
    }

    if (h < 2 || h > 10 || w < 2 || w > 10) {
        printf("Range error\n");
        return 1;
    }

    for (int row = 1; row <= h; row++) {
        for (int column = 1; column <= w; column++) {
            if (row == 1 || row == h ||
                column == 1 || column == w) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}