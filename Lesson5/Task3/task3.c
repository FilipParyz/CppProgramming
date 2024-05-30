#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void add_to_beginning(struct Node** head, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    
    new_node->next = *head;
    
    *head = new_node;
}

void remove_first(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void remove_last(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    struct Node* temp = current->next;
    current->next = NULL;
    free(temp);
}

int main() {
    struct Node* head = NULL;
    
    add_to_beginning(&head, 3);
    add_to_beginning(&head, 2);
    add_to_beginning(&head, 1);
    
    struct Node* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    
    remove_first(&head);
    
    current = head;
    printf("Linked list after removing first element: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    remove_last(&head);

    current = head;
    printf("Linked list after removing last element: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    
    return 0;
}