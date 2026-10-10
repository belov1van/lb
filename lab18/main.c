/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 18
 */

#include <stdio.h>

typedef struct {
    int width;
    int height;
} Rectangle;

long long area(Rectangle r) {
    return (long long)r.width * r.height;
}

long long perimeter(Rectangle r) {
    return 2LL * (r.width + r.height);
}

int main(void) {
    Rectangle rect;

    printf("Введите ширину и высоту (1..1000): ");
    if (scanf("%d %d", &rect.width, &rect.height) != 2) {
        printf("Ошибка ввода\n");
        return 1;
    }

    if (rect.width < 1 || rect.width > 1000 ||
        rect.height < 1 || rect.height > 1000) {
        printf("Ошибка диапазона\n");
        return 1;
    }

    printf("Площадь = %lld\n", area(rect));
    printf("Периметр = %lld\n", perimeter(rect));

    return 0;
}