/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 14
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char text[32];

    if (fgets(text, sizeof text, stdin) == NULL) {
        printf("Ошибка ввода\n");
        return 1;
    }

    size_t pos = strcspn(text, "\n");
    if (text[pos] == '\n') {
        text[pos] = '\0';
    }

    if (strlen(text) > 30) {
        printf("Слишком длинная строка\n");
        return 1;
    }

    int digits = 0;
    int spaces = 0;

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            digits++;
        } else if (text[i] == ' ') {
            spaces++;
        }
    }

    printf("Строка: [%s]\n", text);
    printf("Цифр: %d\n", digits);
    printf("Пробелов: %d\n", spaces);

    return 0;
}