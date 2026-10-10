/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 19
 */

#include <stdio.h>

typedef struct {
    int id;
    int count;
} Item;

int find(const Item a[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (a[i].id == id) {
            return i;
        }
    }
    return -1;
}

void list(const Item a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", a[i].id, a[i].count);
    }
}

int main(void) {
    Item a[] = {{101, 3}, {205, 8}, {310, 0}};
    int n = (int)(sizeof a / sizeof a[0]);
    int command;

    for (;;) {
        printf("1 Список | 2 Поиск | 3 Изменить | 0 Выход\n");
        if (scanf("%d", &command) != 1) {
            return 1;
        }

        if (command == 0) {
            break;
        }

        if (command == 1) {
            list(a, n);
        } else if (command == 2) {
            int id;
            if (scanf("%d", &id) != 1) {
                return 1;
            }
            int k = find(a, n, id);
            if (k < 0) {
                printf("Не найдено\n");
            } else {
                printf("Количество = %d\n", a[k].count);
            }
        } else if (command == 3) {
            int id, value;
            if (scanf("%d %d", &id, &value) != 2) {
                return 1;
            }
            if (value < 0 || value > 1000) {
                printf("Ошибка диапазона\n");
                continue;
            }
            int k = find(a, n, id);
            if (k < 0) {
                printf("Не найдено\n");
            } else {
                a[k].count = value;
                printf("Изменено\n");
            }
        } else {
            printf("Неизвестная команда\n");
        }
    }

    return 0;
}