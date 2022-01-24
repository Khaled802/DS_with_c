#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// node to make linked list
typedef struct node
{
    int val; // store the value
    struct node *next; // store the address of the next node
}Node;

// stack content
typedef struct stack
{
    Node *top; // the peek element
    int size; // the current size of the state
}Stack;

// initialize the stack (constructor)
void init_stack(Stack *stc)
{
    stc->top = NULL; // initialize the top by null value
    stc->size = 0; // initialize the size with zero
}

// check if the stack empty or not
bool is_empty(Stack *stc)
{
    return !stc->size; // if size == 0 that means that the stack is empty
}

// add new element to the stack 
void push(Stack *stc, int val)
{
    // make new node
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->next = stc->top; // assign the value in the new node
    new_node->val = val; // make the new new node point on the next node
    stc->top = new_node; // make the new node the top of the stack
    stc->size++;// increase the size of the stack

}

// remove the top element of the stack
int pop(Stack *stc)
{
    assert(stc->size);// show error when the stack is empty(size==0)
    Node *deleted = stc->top; // store the top to delete it 
    int val = deleted->val; // store its value to return it
    stc->top = stc->top->next; // change the top to the next
    stc->size--; // decrease the size
    free(deleted); // delete the node from the memory
    return val;
}

// iterate on the elements of the stack serially and print its values
void display(Stack *stc)
{
    Node *it = stc->top;
    while (it != NULL)
    {
        printf("%d\n", it->val);
        it = it->next;
    }
    printf("\n");
}


int main()
{
    // make new stack
    Stack *s = (Stack *)malloc(sizeof(Stack));
    // initialize it
    init_stack(s);
    display(s); // print its content (no thing happen except printing new line)
    push(s, 10);
    display(s);
    push(s, 20);
    display(s);
    printf("%d\n", pop(s)); // remove the top and print its value
    return 0;
}
