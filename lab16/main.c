/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 16
 */

#include <stdio.h>

int count_key(const int a[], int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            count++;
        }
    }
    return count;
}

int first_key(const int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int a[] = {2, 7, 2, -1, 2};
    int n = (int)(sizeof a / sizeof a[0]);

    int keys[] = {2, 7, 9};
    for (int i = 0; i < 3; i++) {
        int key = keys[i];
        printf("key=%d: количество=%d; первый индекс=%d\n",
               key, count_key(a, n, key), first_key(a, n, key));
    }

    int own = -1;
    printf("key=%d: количество=%d; первый индекс=%d\n",
           own, count_key(a, n, own), first_key(a, n, own));

    return 0;
}