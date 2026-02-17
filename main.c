


#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    Stack stack;
    initStack(&stack);
    char* filename = NULL;

    if (argc > 2 && strcmp(argv[1], "--file") == 0){
        filename = argv[2];
        printf("Данные из файла: %s\n", filename);

        if (!loadStackFromFile(&stack, filename)){
            fprintf(stderr, "Не удалось открыть файл\n");
            return 1;
        }

        printf("Предыдущий введёнынй ряд: ");
        printStack(&stack);
    }

    else{
        printf("Введите числа с клавиатуры через пробел: ");
        char input[1024];
        fgets(input, sizeof(input), stdin);

        char *token = strtok(input, "\n");
        while (token != NULL){
            push(&stack, atoi(token));
            token = strtok(NULL, "\n");
        }
    }

    saveStackToFile(&stack, "input_original.txt");

    Stack stackForInsertion;
    initStack(&stackForInsertion);
    loadStackFromFile(&stackForInsertion, "input_original.txt");
    printf("Сортировка прямым включением");
    clock_t start = clock();
    insertionSortStack(&stackForInsertion);
    clock_t end = clock();
    double timeInsertion = ((double)(end - start)) / CLOCKS_PER_SEC;
    saveStackToFile(&stackForInsertion, "output_insertion.txt");
    printf("Отсортированный ряд (методом вставок): ");
    printStack(&stackForInsertion);
    printf("Время: %f секунд\n,", timeInsertion);
    freeStack(&stackForInsertion);

    Stack stackForMerge;
    initStack(&stackForMerge);
    loadStackFromFile(&stackForMerge, "input_original.txt");
    printf("Сортировка слиянием:");
    start = clock();
    sortStackMerge(&stackForMerge);
    end = clock();
    double timeMerge = ((double)(end - start)) / CLOCKS_PER_SEC;
    saveStackToFile(&stackForMerge, "output_merge.txt");
    printf("Отсортированный ряд (методом слияния):");
    printStack(&stackForMerge);
    printf("Время: %f секунд\n,", timeMerge);
    freeStack(&stackForMerge);

    printf("Метод вставок: %f секунд\n,", timeInsertion);
    printf("Метод слияния: %f секунд\n,", timeInsertion);

    freeStack(&stack);

    return 0;
}