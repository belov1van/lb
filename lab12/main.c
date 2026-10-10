/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 12
 */

#include <stdio.h>

void order_pair(int *a, int *b) {
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void print_pair(const char *label, int a, int b) {
    printf("%s: %d %d\n", label, a, b);
}

int main(void) {
    int x1 = 7, y1 = 4;
    print_pair("До", x1, y1);
    order_pair(&x1, &y1);
    print_pair("После", x1, y1);

    int x2 = -2, y2 = 0;
    print_pair("До", x2, y2);
    order_pair(&x2, &y2);
    print_pair("После", x2, y2);

    int x3 = 5, y3 = 5;
    print_pair("До", x3, y3);
    order_pair(&x3, &y3);
    print_pair("После", x3, y3);

    int x4 = 0, y4 = -3;
    print_pair("До", x4, y4);
    order_pair(&x4, &y4);
    print_pair("После", x4, y4);

    return 0;
}