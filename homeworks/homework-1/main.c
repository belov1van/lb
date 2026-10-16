/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Домашнее задание 1
 */


#include <stdio.h>

#define MAX_SIZE 100

void inputArray(int array[], int size);
void printArray(const int array[], int size);
int findMin(const int array[], int size);
int findMinIndex(const int array[], int size);
int findMax(const int array[], int size);
int findMaxIndex(const int array[], int size);
long long calculateSum(const int array[], int size);
double calculateAverage(const int array[], int size);
void countSigns(const int array[], int size,
                int *positives, int *negatives, int *zeros);
void countParity(const int array[], int size,
                 int *evens, int *odds);
void printInRange(const int array[], int size, int a, int b);
void performIndividualTask(const int array[], int size);

int main(void) {
    int array[MAX_SIZE];
    int size;

    printf("Введите размер массива от 1 до %d: ", MAX_SIZE);

    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    inputArray(array, size);

    printf("\nИсходный массив:\n");
    printArray(array, size);

    int minVal = findMin(array, size);
    int minIdx = findMinIndex(array, size);
    int maxVal = findMax(array, size);
    int maxIdx = findMaxIndex(array, size);

    printf("\nМинимальный элемент: %d (первый индекс: %d)\n", minVal, minIdx);
    printf("Максимальный элемент: %d (первый индекс: %d)\n", maxVal, maxIdx);

    long long sum = calculateSum(array, size);
    double avg = calculateAverage(array, size);

    printf("Сумма элементов: %lld\n", sum);
    printf("Среднее арифметическое: %.2f\n", avg);

    int positives, negatives, zeros;
    countSigns(array, size, &positives, &negatives, &zeros);

    printf("\nПоложительных: %d\n", positives);
    printf("Отрицательных: %d\n", negatives);
    printf("Нулевых:       %d\n", zeros);

    int evens, odds;
    countParity(array, size, &evens, &odds);

    printf("Чётных:        %d\n", evens);
    printf("Нечётных:      %d\n", odds);

    int a, b;
    printf("\nВведите границы диапазона [a, b]: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Ошибка ввода границ диапазона. Шаг пропущен.\n");
    } else {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        printf("Элементы в диапазоне [%d, %d]:\n", a, b);
        printInRange(array, size, a, b);
    }

    printf("\nИндивидуальное задание (вариант 1):\n");
    performIndividualTask(array, size);

    return 0;
}

void inputArray(int array[], int size) {
    printf("Введите %d целых чисел:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Ошибка ввода. Элемент %d установлен в 0.\n", i);
            array[i] = 0;
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }
        }
    }
}

void printArray(const int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int findMin(const int array[], int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

 /*
                                                    * findMinIndex — возвращает индекс ПЕРВОГО минимального элемента.
                                                    * Строгое неравенство (<) гарантирует, что при повторе минимума
                                                    * мы не затрём первый найденный индекс.
                                                */

int findMinIndex(const int array[], int size) {
    int idx = 0;                                 // переменная со значением 0             
    for (int i = 1; i < size; i++) {            
        if (array[i] < array[idx]) {            
            idx = i;
        }
    }
    return idx;
}

int findMax(const int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int findMaxIndex(const int array[], int size) {
    int idx = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > array[idx]) {
            idx = i;
        }
    }
    return idx;
}

long long calculateSum(const int array[], int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

double calculateAverage(const int array[], int size) {
    long long sum = calculateSum(array, size);
    return (double)sum / size;
}

void countSigns(const int array[], int size,
                int *positives, int *negatives, int *zeros) {
    *positives = 0;
    *negatives = 0;    // обнуляет значение
    *zeros = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            (*positives)++;
        } else if (array[i] < 0) {
            (*negatives)++;
        } else {
            (*zeros)++;
        }
    }
}

void countParity(const int array[], int size, int *evens, int *odds) {
    *evens = 0;
    *odds = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            (*evens)++;
        } else {
            (*odds)++;
        }
    }
}

void printInRange(const int array[], int size, int a, int b) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] >= a && array[i] <= b) {
            printf("array[%d] = %d\n", i, array[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Элементов в заданном диапазоне нет.\n");
    }
}

void performIndividualTask(const int array[], int size) {
    double avg = calculateAverage(array, size);

    printf("Среднее арифметическое = %.2f\n", avg);
    printf("Элементы, строго большие среднего:\n");

    int found = 0;
    for (int i = 0; i < size; i++) {
        if ((double)array[i] > avg) {
            printf("array[%d] = %d\n", i, array[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Таких элементов нет.\n");
    }
}