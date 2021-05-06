//
//  list.c
//  ALDA_ExerciseLists
//
//  Created by Michael Strommer on 26.04.21.
//


#include "list.h"
#include "malloc.h"

void push(node **head_ref, char new_data) {
    node *new_node = (node *) malloc(sizeof(node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;


}

void append(node **head_ref, char new_data) {
    node *new_node = (node *) malloc(sizeof(node));

    node *last = *head_ref;
    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}


/* Given a reference (pointer to pointer) to the head of a list
   and a position, deletes the node at the given position */
void deleteNode(node **head_ref, int position) {
    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // Store head node
    node *temp = *head_ref;

    // If head needs to be removed
    if (position == 0) {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    node *next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next);  // Free memory

    temp->next = next;  // Unlink the deleted node from list
}

// This function prints contents of linked list starting from
// the given node
void printList(node *node) {
    printf("Lichterkette: ");
    while (node != NULL) {
        if(node->next != NULL)
            printf(" %c - ", node->data);
        else
            printf(" %c ", node->data);
        node = node->next;
    }
}


/* Function to reverse the linked list */
static void reverse(node **head_ref) {
    node *prev = NULL;
    node *current = *head_ref;
    node *next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}


struct element *insert(char data, int p, struct element **list) {
    struct element *h = *list;
    struct element *n;

    n = (struct element *) malloc(sizeof(struct element));
    n->data = data;

    if (*list == NULL) {
        n->next = n;
        n->prev = n;
        return n;
    }

    for (int i = 0; i < p - 1; i++) {
        h = h->next;  // (*h).next;
    }

    n->prev = h;
    n->next = h->next;
    n->next->prev = n;
    n->prev->next = n;

    if (p == 0) {
        *list = n;
    }
    return n;
}

void helloWorld(node **list) {

    char input = 'i';
    while (input != 'x') {
        printf("m:");
        scanf(" %c", &input);

        switch (input) {
            case 'a':
                while (input != '0') {
                    printf("l:");
                    scanf(" %c", &input);
                    if (input != '0')
                        push(list, input);
                }
                printList(*list);
                printf("\n");
                break;
            case 'e':
                while (input != '0') {
                    printf("l:");
                    scanf(" %c", &input);
                    if (input != '0')
                        append(list, input);
                }
                printList(*list);
                printf("\n");
                break;
            case 'l':
                printf("p:");
                int pos;
                scanf(" %d", &pos);
                deleteNode(list,pos-1);
                printList(*list);
                printf("\n");
                break;
            case 'i':
                printf("p:");
                int pos1;
                scanf(" %d", &pos1);
                printf("l:");
                scanf(" %c", &input);
                insert(input,pos1,list);
                printList(*list);
                printf("\n");
                break;
            case 'u':
                reverse(list);
                printList(*list);
                printf("\n");
                break;
        }
    }
}