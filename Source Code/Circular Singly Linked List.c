#include<stdio.h>
#include<stdlib.h>

struct linked_list{
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;
node *head = NULL, *tail = NULL;

void insert_at_head(int number);
void insert_at_tail(int number);
void insert_at_middle(int number, int position);
void delete_head();
void delete_tail();
void delete_middle_node(int position);
void print_list();
int getListLength();

int main()
{
    insert_at_head(4);
    insert_at_tail(9);
    insert_at_tail(89);
    insert_at_head(8);
    insert_at_head(9);
    insert_at_head(18);

    printf("Full list:\n");
    print_list();

    printf("List Length: %d\n", getListLength());

    return 0;
}

// Insert a node at front of a circular singly linked list
void insert_at_head(int number)
{
    node *newNode = (node *) malloc(sizeof(node));

    newNode->number = number;
    newNode->next = newNode;

    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }

}

// Insert a node at tail of a circular singly linked list
void insert_at_tail(int number)
{
    node *newNode = (node *) malloc(sizeof(node));

    newNode->number = number;
    newNode->next = newNode;

    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

// Insert a node at middle of a circular singly linked list
void insert_at_middle(int number, int position)
{

}

// Print all node's data of a circular singly linked list
void print_list()
{
    if(head==NULL)  return;

    node *current = head;

    do
    {
        printf("%d ", current->number);
        current = current->next;
    }   while(current != head);
    puts("");
}

//Determine the number of nodes in circular singly linked list
int getListLength()
{
    if(head==NULL) return 0;

    int count = 0;
    node *current = head;

    do
    {
        count++;
        current = current->next;
    }   while(current != head);

    return count;
}
