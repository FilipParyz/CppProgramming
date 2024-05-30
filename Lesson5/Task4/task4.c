#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void print_linked_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

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

void remove_at_index(struct Node** head, int index) {
    if (*head == NULL) {
        return;
    }
    
    if (index == 0) {
        remove_first(head);
        return;
    }
    
    struct Node* current = *head;
    struct Node* previous = NULL;
    int count = 0;
    
    while (current != NULL && count < index) {
        previous = current;
        current = current->next;
        count++;
    }
    
    if (current == NULL) {
        return;
    }
    
    previous->next = current->next;
    free(current);
}

int main() {
    struct Node* head = NULL;
    
    for (int i = 10; i >= 0; i--) {
        add_to_beginning(&head, i);
    }
    
    printf("Linked list: ");
    print_linked_list(head);
    
    remove_first(&head);
    printf("Linked list after removing first element: ");
    print_linked_list(head);

    remove_last(&head);
    printf("Linked list after removing last element: ");
    print_linked_list(head);

    remove_at_index(&head, 3);
    printf("Linked list after removing element at index 3: ");
    print_linked_list(head);

    return 0;
}