#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void add_to_beggining(struct Node** head, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    
    new_node->next = *head;
    
    *head = new_node;
}

int main() {
    struct Node* head = NULL;
    
    add_to_beggining(&head, 3);
    add_to_beggining(&head, 2);
    add_to_beggining(&head, 1);
    
    struct Node* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    
    return 0;
}