/*
Stack implementation with Array
Code written by Hasan Abdullah
Contact: hellohasan.com
*/
#include<stdio.h>
#define stackSize 3

int myStack[stackSize], top = -1;

void push(int value)
{
    if(top>=stackSize-1)
        printf("Stack is full!\n");
    else
    {
        printf("PUSH: %d\n", value);
        myStack[++top] = value;
    }

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
    {
        printf("Popped %d, from Stack\n", myStack[top]);
        top--;
    }

}

void displayStack()
{
    printf("\nPrint the full stack from TOP to BOTTOM:\n");
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
