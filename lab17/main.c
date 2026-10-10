/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 17
 */

#include <stdio.h>

void sort_desc(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max_index]) {
                max_index = j;
            }
        }
        int t = a[i];
        a[i] = a[max_index];
        a[max_index] = t;
    }
}

int is_descending(const int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void print_array(const char *label, const int a[], int n) {
    printf("%s: ", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}

int main(void) {
    int a[] = {4, -2, 7, 4, 0};
    int n = (int)(sizeof a / sizeof a[0]);

    print_array("До сортировки", a, n);
    sort_desc(a, n);
    print_array("После сортировки", a, n);
    printf("Проверка по убыванию: %d\n", is_descending(a, n));

    int single[] = {5};
    print_array("Один элемент", single, 1);
    printf("Проверка по убыванию: %d\n", is_descending(single, 1));

    int unsorted[] = {3, 1, 2};
    print_array("Не отсортирован", unsorted, 3);
    printf("Проверка по убыванию: %d\n", is_descending(unsorted, 3));

    return 0;
}