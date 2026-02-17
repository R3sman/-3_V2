


#ifndef STACK
#define STACK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
// элемент стека
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// стек (указатель на вершину стека)
typedef struct {
    Node* top;
} Stack;

//функции
void initStack(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int isEmpty(Stack* s);
void printStack(Stack* s);
void freeStack(Stack* s);
int saveStackToFile(Stack* s, const char* filename);
int loadStackFromFile(Stack* s, const char* filename);

//сортировки
void insertionSortStack(Stack* s);
Node* mergeSortStack(Node* head);
void sortStackMerge(Stack* s);

#endif