


#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void insertionSortStack(Stack* s) {
    if (isEmpty(s) || s -> top -> next == NULL) {
        return;
    }

    Node* sorted = NULL;
    Node* current = s -> top;

    while (current != NULL) {
        Node* next = current -> next;
    

        if (sorted == NULL || current -> data < sorted -> data) {
            current -> next = sorted;
            sorted = current;
        }

        else {
            Node* temp = sorted;
            while (temp -> next != NULL && temp -> next -> data < current -> data) {
                temp = temp -> next;
            }

            current -> next = temp -> next;
            temp -> next = current;
        }

        current = next;
    }

    s -> top = sorted;
}