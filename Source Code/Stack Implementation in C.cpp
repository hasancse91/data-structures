/*
Stack implementation with Array
Code written by Hasan Abdullah
Contact: hellohasan.com
*/
#include<stdio.h>
#define stackSize 100

int myStack[stackSize], top = -1;

void push(int value)
{
    if(top>=stackSize)
        printf("Stack is full!\n");
    else
        myStack[++top] = value;
}

void peek()
{
    if(top<0)
        printf("Stack Underflow!\n");
    else
        printf("%d\n", myStack[top]);
}

void pop()
{
    if(top<0)
        printf("Stack underflow!\n");
    else
        top--;
}

void displayStack()
{
    printf("Print the full stack from TOP to BOTTOM:\n");
    for(int i = top; i>=0; i--)
        printf("%d\n",myStack[i]);
}

int main()
{
    push(5);
    push(90);
    push(12);

    displayStack();

    pop();

    displayStack();

    printf("\nTop value of this Stack:   ");
    peek();


    return 0;
}
