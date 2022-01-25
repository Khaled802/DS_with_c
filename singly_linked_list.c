#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// node used to make the linked list
typedef struct node
{
    int val; // the value of the node
    struct node *next; // the next value of this node
}Node;

// structure of the linked list
typedef struct linked_list
{
    Node *begin; // the first node at the linked list
    Node *end; // last node at the linked list
    int size; // the current size of the linked list
}Linked_List;


// initialization of the linked list (constructor)
void init_lls(Linked_List *l)
{
    l->begin = NULL;
    l->end = NULL;
    l->size = 0;
}

// check if it is empty or not
bool is_empty(Linked_List *l)
{
    return l->size == 0; // can use also begin and end to make sure it is empty
}

// make new node with value val and return its address;
Node *make_node(int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;
}

// used in inserting new node when the linked list is empty from elements to make the node
void push_empty(Linked_List *l, int val)
{
    Node *new_node = make_node(val);
    l->begin = l->end = new_node; // assign the the begin and end with new node as it is the only element at the array
    l->size++; // increasing the size
}

// inserting new element at the beginning of the linked list
void push_front(Linked_List *l, int val)
{
    // state the linked list is empty
    if (is_empty(l))
    {
        push_empty(l, val);
        return;
    }
    Node *new_node = make_node(val);
    new_node->next = l->begin; // link the node from the beginning of the linked list
    l->begin = new_node; // changing the begin of the linked list to the new node
    l->size++; // increase the size
}

// inserting new element at the end of the linked list
void push_back(Linked_List *l, int val)
{
    // state of empty linked list
    if (is_empty(l))
    {
         push_empty(l, val);
        return;
    }
    Node *new_node = make_node(val);
    l->end->next = new_node; // link the new node with the end of the linked list
    l->end = new_node; // changing the end of the linked list
    l->size++; // increase the size of the linked list
}

// remove the last element of the linked list
void pop_back(Linked_List *l)
{
    assert(!is_empty(l)); // show error when the linked list is empty
    // getting the node before last element
    Node *pre = l->begin;
    if (pre == l->end)
    {
        pre = l->begin = NULL;
    }
    else
    {
       while (pre->next->next)
        {
            pre = pre->next;
        }
    }
    // store the address of the last node to delete it
    Node *deleteIt = l->end;
    int val = deleteIt->val; // store the value of the last node to  return it
    l->end = pre; // assign the new end with the node of the previous node or NULL if the last doesn't have previous
    // when the new end not NULL assign the next of it with NULL (because it is the last node now)
    if (pre)
        l->end->next = NULL;
    free(deleteIt); // deleting the node
    l->size--; // decrease the size by 1
    return val; // return the value of deleted node
}

int pop_front(Linked_List *l)
{
    assert(!is_empty(l)); // show error when the linked list is empty
    // if the linked list have only one element when delete it, will be empty and end should be NULL
    if (l->begin == l->end)
    {
        l->end = NULL;
    }
    // store the address of the last node to delete it
    Node *deleteIt = l->begin;
    int val = deleteIt->val; // store the value of the last node to  return it
    l->begin = deleteIt->next; // assign the begin to the next of the the first node
    free(deleteIt); // deleting the node
    l->size--; // decreasing the size
    return val; // return the value deleted
}

// iterate on the whole(traverse) linked list and print its values
void display(Linked_List *l)
{
    Node *i = l->begin;
    for(;i != NULL; i = i->next)
    {
        printf("%d ", i->val);
    }
    printf("\n");
}

// return the value of the first element of the linked list
int front(Linked_List *l)
{
    if (l->begin)
        return l->begin->val;
    // if the linked is empty the is no nodes in front
    printf("It is empty linked list\n");
    return 0;
}

// return the value of the last element of the linked list
int back(Linked_List *l)
{
    if (l->end)
        return l->end->val;
    // if the linked is empty the is no nodes in front
    printf("It is empty linked list\n");
    return 0;
}

int main()
{
    Linked_List l;
    init_lls(&l);
    push_back(&l, 10);
    display(&l);
    push_back(&l, 20);
    display(&l);
    push_front(&l, 0);
    display(&l);
    pop_back(&l);
    display(&l);
    printf("front: %d\n", front(&l));
    printf("rear: %d\n", back(&l));
    pop_front(&l);
    printf("\n");
    printf("front: %d\n", front(&l));
    printf("rear: %d\n", back(&l));
    pop_front(&l);
    display(&l);
   // pop_front(&l);
    printf("front: %d\n", front(&l));
    printf("rear: %d\n", back(&l));

    return 0;
}
