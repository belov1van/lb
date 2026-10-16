/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 23
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t size = 0, capacity = 2;
    int *a = malloc(capacity * sizeof *a);
    if (a == NULL) {
        printf("Ошибка памяти\n");
        return 1;
    }

    for (int value = 1; value <= 10; value++) {
        if (size == capacity) {
            size_t next = capacity * 2;
            int *temp = realloc(a, next * sizeof *a);
            if (temp == NULL) {
                free(a);
                printf("Ошибка памяти\n");
                return 1;
            }
            a = temp;
            capacity = next;
            printf("Рост вместимости: %zu\n", capacity);
        }
        a[size++] = value;
    }

    printf("Size=%zu Capacity=%zu\n", size, capacity);
    for (size_t i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');

    free(a);
    a = NULL;
    return 0;
}