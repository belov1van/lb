/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 21
 */


#include <stdio.h>

typedef struct {
    int id;
    int score;
} Result;

int main(void) {
    Result a[] = {{101, 80}, {205, 95}, {310, 60}};
    int n = (int)(sizeof a / sizeof a[0]);

    FILE *f = fopen("passed.txt", "w");
    if (f == NULL) {
        printf("Ошибка открытия\n");
        return 1;
    }

    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (a[i].score >= 80) {
            if (fprintf(f, "%d %d\n", a[i].id, a[i].score) < 0) {
                ok = 0;
            }
        }
    }

    if (fclose(f) != 0) {
        ok = 0;
    }

    if (!ok) {
        printf("Ошибка записи\n");
        return 1;
    }

    printf("Сохранено passed.txt\n");
    return 0;
}