


#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//разделение списка на две половины
void splitList(Node* source, Node** frontRef, Node** backRef) {
    Node* slow = source;
    Node* fast = source -> next;

    while (fast != NULL) {
        fast = fast -> next;

        if (fast != NULL) {
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    *frontRef = source;
    *backRef = slow -> next;
    slow -> next = NULL;
}   

//слияние двух отсортированных списков
Node* mergeSortedLists(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* result = NULL;

    if (a -> data <= b -> data) {
        result = a;
        result -> next = mergeSortedLists(a -> next, b);
    }

    else {
        result = b;
        result -> next = mergeSortedLists(a, b -> next);
    }

    return result;
}

//рекурсивная функция сортировки слиянием
Node* mergeSortStack(Node* head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    Node* a;
    Node* b;

    splitList(head, &a, &b);

    a = mergeSortStack(a);
    b = mergeSortStack(b);

    return mergeSortedLists(a, b);
}

void sortStackMerge(Stack* s) {
    s -> top = mergeSortStack(s -> top);
}