#include<stdio.h>
#include<stdlib.h>
#define NULL 0

struct linked_list
{
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;

void create(node *myList);
void print(node *myList);
int countListItem(node *myList);

int main()
{
    node *head;
    head = (node *) malloc(sizeof(node));

    create(head);

    printf("\n");
    print(head);
    printf("\n");

    printf("\nNumber of items = %d \n", countListItem(head));

    return 0;
}

void create(node *myList)
{
    printf("Input a number. (Enter -99999 at end)\n");

    scanf("%d", &myList->number);

    if(myList->number==-99999)
        myList->next = NULL;
    else
    {
        myList->next = (node *) malloc(sizeof(node));
        create(myList->next);
    }
}

void print(node *myList)
{
    printf("%d ", myList->number);

    if(myList->next == NULL)
        return;

    print(myList->next);
}

int countListItem(node *myList)
{
    if(myList->next == NULL)
        return 0;

    return (1 + countListItem(myList->next));
}

