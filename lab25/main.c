/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 25
 */

#include <stdio.h>

int search_rec(const int a[], int left, int right, int key) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (a[mid] == key) {
        return mid;
    }
    if (key < a[mid]) {
        return search_rec(a, left, mid - 1, key);
    }
    return search_rec(a, mid + 1, right, key);
}

int search_iter(const int a[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key) {
            return mid;
        }
        if (a[mid] < key) {
            left = mid + 1;

/*
    if (a[mid] == key) {
        return -1;  // намеренная ошибка
    }

    output: Расхождение: ключ=-4 рекурсивный=-1 итеративный=0
*/

        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int a[] = {-4, -1, 2, 6, 9};
    int n = (int)(sizeof a / sizeof a[0]);

    int mismatch = 0;
    for (int key = -5; key <= 10; key++) {
        int r = search_rec(a, 0, n - 1, key);
        int i = search_iter(a, n, key);
        if (r != i) {
            printf("Расхождение: ключ=%d рекурсивный=%d итеративный=%d\n", key, r, i);
            mismatch = 1;
        }
    }

    if (!mismatch) {
        printf("OK\n");
    }

    return 0;
}