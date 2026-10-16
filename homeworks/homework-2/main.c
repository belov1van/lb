#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    int score;
} Result;

int load(const char *path, Result a[], int *size) {
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        return 0;
    }

    int count = 0;
    int id, score;

    while (fscanf(f, "%d %d", &id, &score) == 2) {
        if (count >= MAX_SIZE) {
            fclose(f);
            return 0;
        }
        if (id < 1 || id > 9999 || score < 0 || score > 100) {
            fclose(f);
            return 0;
        }
        for (int i = 0; i < count; i++) {
            if (a[i].id == id) {
                fclose(f);
                return 0;
            }
        }
        a[count].id = id;
        a[count].score = score;
        count++;
    }

    int ch;
    while ((ch = fgetc(f)) != EOF) {
        if (ch != ' ' && ch != '\n' && ch != '\t' && ch != '\r') {
            fclose(f);
            return 0;
        }
    }

    if (fclose(f) != 0) {
        return 0;
    }

    *size = count;
    return 1;
}

void show(const Result a[], int n) {
    if (n == 0) {
        printf("No data\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", a[i].id, a[i].score);
    }
}

void statistics(const Result a[], int n) {
    if (n == 0) {
        printf("No data\n");
        return;
    }

    long long sum = 0;
    int passed = 0;
    int minIdx = 0, maxIdx = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i].score;
        if (a[i].score >= 60) {
            passed++;
        }
        if (a[i].score < a[minIdx].score) {
            minIdx = i;
        }
        if (a[i].score > a[maxIdx].score) {
            maxIdx = i;
        }
    }

    double avg = (double)sum / n;

    printf("Count = %d\n", n);
    printf("Average = %.2f\n", avg);
    printf("Passed = %d\n", passed);
    printf("Min = %d %d\n", a[minIdx].id, a[minIdx].score);
    printf("Max = %d %d\n", a[maxIdx].id, a[maxIdx].score);
}

int find(const Result a[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (a[i].id == id) {
            return i;
        }
    }
    return -1;
}

/* Вариант 2: строгий порог — балл строго больше 80 */
void individual(const Result a[], int n) {
    if (n == 0) {
        printf("No data\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].score > 80) {
            printf("%d %d\n", a[i].id, a[i].score);
            found = 1;
        }
    }
    if (!found) {
        printf("No matches\n");
    }
}

int save(const Result a[], int n, const char *path) {
    FILE *f = fopen(path, "w");
    if (f == NULL) {
        return 0;
    }
    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (fprintf(f, "%d %d\n", a[i].id, a[i].score) < 0) {
            ok = 0;
        }
    }
    if (fclose(f) != 0) {
        ok = 0;
    }
    return ok;
}

int main(void) {
    Result data[MAX_SIZE];
    int size = 0;

    if (!load("results.txt", data, &size)) {
        printf("Load error\n");
        return 1;
    }

    int command;
    for (;;) {
        printf("1 List | 2 Stats | 3 Find | 4 Variant | 5 Save | 0 Exit\n");
        if (scanf("%d", &command) != 1) {
            printf("Input error\n");
            return 1;
        }

        if (command == 0) {
            break;
        } else if (command == 1) {
            show(data, size);
        } else if (command == 2) {
            statistics(data, size);
        } else if (command == 3) {
            int id;
            if (scanf("%d", &id) != 1) {
                printf("Input error\n");
                return 1;
            }
            int k = find(data, size, id);
            if (k < 0) {
                printf("Not found\n");
            } else {
                printf("%d %d\n", data[k].id, data[k].score);
            }
        } else if (command == 4) {
            individual(data, size);
        } else if (command == 5) {
            if (!save(data, size, "report.txt")) {
                printf("Write error\n");
                return 1;
            }
            printf("Saved report.txt\n");
        } else {
            printf("Unknown command\n");
        }
    }

    return 0;
}