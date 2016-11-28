/*
Queue implementation with Array
Code written by Hasan Abdullah
Contact: hellohasan.com
*/
#include<stdio.h>
#define queueSize 100

int myQueue[queueSize], front = 0, rear = -1;


void enqueue(int value)
{
    if(rear==queueSize)
        printf("Queue is full! Cannot insert any Data!\n");
    else
        myQueue[++rear] = value;
}

void dequeue()
{
    if(front==queueSize)
        printf("Queue is empty!\n");
    else
        printf("Dequeued value: %d\n", myQueue[front++]);
}

void display()
{
    int i;

    for(i = front; i<=rear; i++)
        printf("%d\n", myQueue[i]);
}

int main()
{
    for(int i = 10; i<=100; i=i+10)
    {
        enqueue(i); //push 10 elements in queue
    }

    //Display the queue
    printf("Full Queue is:\n");
    display();
    puts("");

    dequeue();
    dequeue();

    //Display the updated queue
    printf("\nUpdated Queue is:\n");
    display();
    puts("");

    //Enqueue another value
    enqueue(999);

    //Display the updated queue
    printf("\nUpdated Queue is:\n");
    display();
    puts("");

    return 0;
}
