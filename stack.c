


#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void initStack(Stack* s) {
    s -> top = NULL;
}

void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return;
    }

    newNode -> data = value;
    newNode -> next = s -> top;
    s -> top = newNode;
}

int pop(Stack* s) {
    int value;

    if(isEmpty(s)) {
        fprintf(stderr, "Стек пустой\n");
        return -1;
    }

    Node* temp = s -> top;
    value = temp -> data;
    s -> top = s -> top -> next;
    free(temp);

    return value;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Стек пустой\n");
        return -1;
    }

    return s -> top -> data;
}

int isEmpty(Stack* s) {
    return s -> top == NULL;
}

void printStack(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

void freeStack(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

int saveStackToFile(Stack* s, const char* filename) {
    FILE* file = fopen(filename, "w");

    if (!file) {
        perror("Ошибка открытия файла для записи");
        return 0;
    }

    Node* current = s -> top;
    while (current != NULL) {
        fprintf(file, "%d", current -> data);
        current = current -> next;
    }

    fclose(file);

    return 1;
}

int loadStackFromFile(Stack* s, const char* filename) {
    int value;
    int tempArray[10000];
    int count = 0;

    FILE* file = fopen(filename, "r");

    if (!file) {
        perror("Ошибка открытия файла для чтения");
        return 0;
    }

    freeStack(s);
    initStack(s);

    while (fscanf(file, "%d", &value) == 1) {
        tempArray[count++] = value;
    }

    for (int i = count - 1; i >= 0; i--) {
        push(s, tempArray[i]);
    }

    fclose(file);
    return 1;
}