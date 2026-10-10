/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 20
 */


#include <stdio.h>

int main(void) {
    FILE *f = fopen("numbers.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия\n");
        return 1;
    }

    int x, status, count = 0;
    int max = 0;
    int has_data = 0;

    while ((status = fscanf(f, "%d", &x)) == 1) {
        if (x < -1000 || x > 1000 || count == 100) {
            printf("Ошибка диапазона или размера\n");
            fclose(f);
            return 1;
        }
        if (!has_data || x > max) {
            max = x;
            has_data = 1;
        }
        count++;
    }

    int bad = (status != EOF || ferror(f));
    if (fclose(f) != 0) {
        bad = 1;
    }
    if (bad) {
        printf("Ошибка чтения\n");
        return 1;
    }

    if (!has_data) {
        printf("Нет данных\n");
        return 0;
    }

    printf("Максимум = %d\n", max);
    printf("Количество = %d\n", count);
    return 0;
}