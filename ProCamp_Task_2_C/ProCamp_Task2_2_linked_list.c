// Task2_2:
// Create a Create a linked list library list_add(), list_contains(),
// list_rmove(). Elements in a list shoul be dynamically allocated.

#include "ProCamp_Task2_2_linked_list.h"

#define COUNT  sizeof numbers / sizeof (int)
#define COUNT2 sizeof more_numbers / sizeof (int)

void task2_2_main_linked_list()
{
    printf("Task2_2: a linked list library \n");
    printf("Start \n\n");

    int numbers[] = { 3, 8, 23, 1, 8, 45, 3, 11, 15, 12, 42, 9, 0, 53, 15 };
    int more_numbers[] = { 7, 10, 4, 11 };
    llist* my_list = llist_create(NULL);
    unsigned int i;

    printf("\nPrint the empty list: \n");
    llist_contains(my_list, numprint);

    // Add all of the numbers and sort
    for (i = 0; i < COUNT; i++)
        llist_add_inorder((void*)(numbers + i), my_list, numcmp);

    printf("\nPrint list of sorted numbers: \n");
    llist_contains(my_list, numprint);

    // Remove first five numbers
    for (i = 0; i < COUNT2; i++)
        llist_remove(my_list);

    printf("\nPrint list without first five numbers: \n");
    llist_contains(my_list, numprint);

    // Add numbers to front
    for (i = 0; i < COUNT2; i++)
        llist_add(my_list, &more_numbers[i]);

    printf("\nPrint list with add numbers to front: \n");
    llist_contains(my_list, numprint);

    printf("\nFree the list\n");
    llist_free(my_list);

    printf("\n\n");
    printf("Task2_2: a linked list library \n");
    printf("Stop \n\n");
}

// Returns 0 on failure
int llist_add_inorder(void* data, llist* list, int (*comp)(void*, void*))
{
    struct node* new_node;
    struct node* curr;
    struct node* prev = NULL;

    if (list == NULL || *list == NULL) {
        fprintf(stderr, "llist_add_inorder: list is null\n");
        return 0;
    }

    curr = *list;
    if (curr->data == NULL) {
        curr->data = data;
        return 1;
    }

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    // Find spot in linked list to insert new node
    while (curr != NULL && curr->data != NULL && comp(curr->data, data) < 0) {
        prev = curr;
        curr = curr->next;
    }
    new_node->next = curr;

    if (prev == NULL)
        *list = new_node;
    else
        prev->next = new_node;

    return 1;
}

llist* llist_create(void* new_data)
{
    struct node* new_node;

    llist* new_list = (llist*)malloc(sizeof(llist));
    *new_list = (struct node*)malloc(sizeof(struct node));

    new_node = *new_list;
    new_node->data = new_data;
    new_node->next = NULL;
    return new_list;
}

void llist_free(llist* list)
{
    struct node* curr = *list;
    struct node* next;

    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(list);
}

void llist_add(llist* list, void* data)
{
    struct node* head;
    struct node* new_node;
    if (list == NULL || *list == NULL) {
        fprintf(stderr, "llist_add_inorder: list is null\n");
    }

    head = *list;

    // Head is empty node
    if (head->data == NULL)
        head->data = data;

    // Head is not empty, add new node to front
    else {
        new_node = malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = head;
        *list = new_node;
    }
}

void* llist_remove(llist* list)
{
    void* popped_data;
    struct node* head = *list;

    if (list == NULL || head->data == NULL)
        return NULL;

    popped_data = head->data;
    *list = head->next;

    free(head);

    return popped_data;
}

void llist_contains(llist* list, void (*print)(void*))
{
    struct node* curr = *list;
    while (curr != NULL) {
        print(curr->data);
        printf(" ");
        curr = curr->next;
    }
    putchar('\n');
}

int numcmp(void* a, void* b)
{
    if (*(int*)a < *(int*)b)
        return -1;
    if (*(int*)a > *(int*)b)
        return 1;

    return 0;
}

void numprint(void* num)
{
    int* pnum = (int*)num;
    if (num == NULL)
        return;

    printf("%d", *pnum);
}