/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 15
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char text[32], out[32];

    if (fgets(text, sizeof text, stdin) == NULL) {
        printf("Ошибка ввода\n");
        return 1;
    }

    text[strcspn(text, "\n")] = '\0';

    if (strlen(text) > 30) {
        printf("Слишком длинная строка\n");
        return 1;
    }

    size_t j = 0;
    for (size_t i = 0; text[i] != '\0'; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            out[j++] = text[i];
        }
    }
    out[j] = '\0';

    printf("Исходная: [%s]\n", text);
    printf("Только цифры: [%s]\n", out);

    return 0;
}