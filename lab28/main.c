/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 28
 */

#include <stdio.h>
#include <assert.h>

typedef struct {
    int id;
    int score;
} Result;

double average(const Result a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i].score;
    }
    return n > 0 ? (double)sum / n : 0.0;
}

int passed_count(const Result a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].score >= 60) {
            count++;
        }
    }
    return count;
}

int best_index(const Result a[], int n) {
    if (n <= 0) {
        return -1;
    }
    int best = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].score > a[best].score) {
            best = i;
        }
    }
    return best;
}

int save_passed(const Result a[], int n, const char *path) {
    FILE *f = fopen(path, "w");
    if (f == NULL) {
        return 0;
    }
    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (a[i].score >= 60) {
            if (fprintf(f, "%d %d\n", a[i].id, a[i].score) < 0) {
                ok = 0;
            }
        }
    }
    if (fclose(f) != 0) {
        ok = 0;
    }
    return ok;
}

void run_tests(void) {
    Result t1[] = {{101, 80}, {205, 50}, {310, 95}};
    assert(best_index(t1, 3) == 2);
    assert(passed_count(t1, 3) == 2);

    Result t2[] = {{101, 60}, {205, 60}};
    assert(best_index(t2, 2) == 0);
    assert(passed_count(t2, 2) == 2);

    Result t3[] = {{101, 59}};
    assert(best_index(t3, 1) == 0);
    assert(passed_count(t3, 1) == 0);

    Result t4[] = {{101, 60}};
    assert(passed_count(t4, 1) == 1);

    Result t5[] = {{101, 61}};
    assert(passed_count(t5, 1) == 1);

    assert(best_index(t1, 0) == -1);
    assert(passed_count(t1, 0) == 0);

    puts("All tests passed");
}

int main(void) {
    run_tests();

    Result a[] = {{101, 80}, {205, 50}, {310, 95}};
    int n = (int)(sizeof a / sizeof a[0]);

    int best = best_index(a, n);
    if (best < 0) {
        printf("No data\n");
    } else {
        printf("Best id=%d score=%d\n", a[best].id, a[best].score);
    }

    printf("Average=%.2f\n", average(a, n));
    printf("Passed=%d\n", passed_count(a, n));

    if (!save_passed(a, n, "passed.txt")) {
        printf("Write error\n");
        return 1;
    }
    printf("Saved passed.txt\n");

    return 0;
}