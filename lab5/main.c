/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 5
 */

#include <stdio.h>

int main(void) {
    int number;
    int count = 0;
    int positiveCount = 0;
    long long sum = 0; 

    printf("Статистика последовательности\n");
    printf("Введите целые числа от -1000 до 1000.\n");
    printf("Для завершения введите 0.\n\n");

    while (count < 100) {
        printf("Введите число: ");

        int inputResult = scanf("%d", &number);

        if (inputResult != 1) {
            printf("Ошибка ввода.\n");
            break;
        }

        if (number == 0) {
            break;
        }

        if (number < -1000 || number > 1000) {
            printf("Ошибка: число должно быть от -1000 до 1000.\n");
            continue;
        }

        count++;
        sum += number;

        if (number > 0) {
            positiveCount++;
        }
    }

    printf("\nСтатистика:\n");
    printf("Количество принятых чисел: %d\n", count);
    printf("Сумма чисел: %lld\n", sum);
    printf("Количество положительных чисел: %d\n", positiveCount);

    return 0;
}
