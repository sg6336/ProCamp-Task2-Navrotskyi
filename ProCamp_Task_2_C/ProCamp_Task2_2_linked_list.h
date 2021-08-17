// Task2_2:
// Create a linked list library with functions list_add(), list_contains(),
// list_rmove(). Elements in a list shoul be dynamically allocated.
/*
* void task2_2_main_linked_list(); // main() for task2_2
* 
* int llist_add_inorder(void* data, llist* list, int (*comp)(void*, void*)); // Add to sorted linked list
* llist* llist_create(void* new_data); // Create a linked list
* void llist_free(llist* list); // Free a linked list
* void llist_add(llist* list, void* data); // Add to head of list
* void* llist_remove(llist* list); // remove and return head of linked list 
* void llist_contains(llist* list, void (*print)(void*)); // rint linked list
* int numcmp(void* a, void* b); // for find spot in linked list to insert new node
* void numprint(void* num); // for print corrent data
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>

struct node {
    void* data;
    struct node* next;
};

typedef struct node* llist;

void task2_2_main_linked_list(void);

/* llist_add_inorder: Add to sorted linked list */
int llist_add_inorder(void*, llist*, int (*)(void*, void*));

/* llist_create: Create a linked list */
llist* llist_create(void*);

/* llist_free: Free a linked list */
void llist_free(llist*);

/* llist_push: Add to head of list */
void llist_add(llist*, void*);

/* llist_pop: remove and return head of linked list */
void* llist_remove(llist*);

/* llist_print: print linked list */
void llist_contains(llist*, void (*)(void*));

int numcmp(void*, void*);
void numprint(void*);