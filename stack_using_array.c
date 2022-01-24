#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// make struct of stack
typedef struct stack
{
    int *arr; // the pointer to the array that sorter the elements in it
    int size; // store how many that the stack have now
    int max_size; // the maximum number of elements can stored in stack
}Stack;

// initialization for the stack (constructor)
void init_stack(Stack *stc, int max_size)
{
    // make array with max size
    stc->arr = (int *)malloc(sizeof(int)*max_size);
    stc->max_size = max_size; // assign the max_size
    stc->size = 0; // initialize the size
}

// check if the stack is empty or not
bool is_empty(Stack *stc)
{
    return !stc->size; // if size = 0 that means that the stack is empty
}

bool is_full(Stack *stc)
{
    return stc->size >= stc->max_size; // if the size == max size that means reach the max size
}

// add new element at the stack
void push(Stack *stc, int val)
{
    // this needs to import <assert.h> library
    assert(!is_full(stc)); // show an error when the stack reach max size 'cause cannot add more elements
    stc->arr[stc->size++] = val; // assign value to the index and increase the size of stack
}

// remove an element from the stack
int pop(Stack *stc)
{
    assert(!is_empty(stc)); // show error when the stack is empty
    return stc->arr[--stc->size]; // decrease the size so the top element is not with as any more and return its value
}

// iterating on the stack and printing the elements of it
void display(Stack *stc)
{
    // starting from last element (LIFO)
    int i= stc->size-1;
    for ( ; i >= 0; --i)
    {
        printf("%d\n", stc->arr[i]);
    }
    printf("\n");
}
int main()
{
    Stack s;
    init_stack(&s, 3);
    push(&s, 10);
    printf("%d\n", s.size);
    display(&s);
    push(&s, 20);
    push(&s, 30);
    display(&s);

//    push(&s, 40); // uncomment this will show error as the stack is full
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
   // printf("%d\n", pop(&s));
  //  printf("%d\n", pop(&s)); // uncomment the to line show error as there is no more elements to remove
    printf("\n");
    display(&s);

    return 0;
}
