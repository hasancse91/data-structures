/*
    Doubly Linked List implementation by C programming Language
    Operations: create list, insert item to tail, insert item to first, insert item to middle,
        delete any item according to position,
        print list forward order, print list reverse order
    Programmed by: Hasan Abdullah
    Contact: http://hellohasan.com/
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct linked_list
{
    int number;
    struct linked_list *next;
    struct linked_list *previous;
};

typedef struct linked_list node;
node *head=NULL, *tail=NULL;

node* getNewNode(int val);
void insert_at_head(int value);
void insert_at_tail(int value);
void insert_at_middle(int value, int position);
void deleteNode(int position);
void printLinkedListForward();
void printLinkedListBackward();
bool isValueAvailable(int value);


int main()
{
    int a = 5, b = 15, c = 43, d = 23, e = 12, f = 66, g = 99, h =65, i = 20, j = 8;
    int pos = 2, insertMidValue = 500, deletePos = 4;

    //Create a linked list
    printf("Insert nodes at tail: %d, %d, %d\n", a, b, c);
    insert_at_tail(a);
    insert_at_tail(b);
    insert_at_tail(c);

    //print the list forward
    printLinkedListForward();

    printf("Insert node: %d at middle. Position: %d\n", insertMidValue, pos);
    insert_at_middle(insertMidValue, pos); //here midValue = 500 and pos = 2

    //print the list forward
    printLinkedListForward();

    printf("Delete item of position number %d", deletePos);
    deleteNode(deletePos);

    //print the list forward
    printLinkedListForward();

    printf("Insert nodes at front: %d\n", d);
    insert_at_head(d);

    //print the list forward
    printLinkedListForward();

    printf("Insert nodes at tail: %d\n", e);
    insert_at_tail(e);

    //print the list forward
    printLinkedListForward();

    printf("Insert nodes at front: %d\n", f);
    insert_at_head(f);

    //print the list forward
    printLinkedListForward();

    printf("Delete first node of list\n");
    deleteNode(1);

    //print the list forward
    printLinkedListForward();

    printf("Insert nodes at tail: %d, %d, %d, %d\n", g, h, i, j);
    insert_at_tail(g);
    insert_at_tail(h);
    insert_at_tail(i);
    insert_at_tail(j);

    //print the list forward
    printLinkedListForward();

    //print the list backward
    printLinkedListBackward();
    
    //Searching the value in the list
    int value = h;
    if(isValueAvailable(value) == true)
        printf("%d found in the list.\n\n", value);
    else
        printf("%d not found in the list.\n\n", value);
    return 0;
}


/*
    User defined functions
*/

//create a new node and returns to caller
node* getNewNode(int val)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));
    temp_node->number=val;
    temp_node->next=NULL;
    temp_node->previous=NULL;

    return temp_node;
}

//Insert a node at front of the list. This node will be the new head
void insert_at_head(int value)
{
    node *newNode = getNewNode(value);

    if(head==NULL) //For the 1st element
    {
        //For now, newNode is the only one node of list
        //So it it is head and also tail
        head=newNode;
        tail=newNode;
        return;
    }

    //newNode will be the NEW HEAD of list.
    //So it'll point to head as 'next node'
    newNode->next = head;
    head->previous = newNode; //before, the previous node of head was NULL. but now newNode

    head = newNode; //update the global node 'head' by newNode
}

//Insert a node after last node
void insert_at_tail(int value)
{
    node *newNode = getNewNode(value);

    if(head==NULL) //For the 1st element
    {
        head=newNode;
        tail=newNode;
        return;
    }

    //'tail' is a global node. 'newNode' will be the next node of tail.
    //finally newNode will be the 'tail' node of the list
    tail->next = newNode;
    newNode->previous = tail; //'newNode' point 'tail' node as previous node

    tail = newNode; // update the global node 'tail' by newNode.
}

//Insert a node at front of the list. This node will be the new head
void insert_at_middle(int value, int position)
{
    node *newNode = getNewNode(value);

    if(head==NULL) //For the 1st element
    {
        //For now, newNode is the only one node of list
        //So it it is head and also tail
        head=newNode;
        tail=newNode;
        return;
    }

    node *temp = (node *) malloc(sizeof(node));
    temp = head;
    int i = 1;

    //find the position where our newNode will put
    while((i < position-1) && temp->next!=NULL){
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next; //newNode's next node will be the next node of temp
    newNode->previous = temp; //newNode's previous node will be the temp node

    if(temp->next)
        temp->next->previous = newNode; //newNode will be the previous node of temp->next node

    temp->next = newNode; //update the next node of temp
}

// delete any node of list according to position
void deleteNode(int position){

    if(head==NULL) return;

    if(position==1){ // delete 1st (head) node
        head = head->next;

        if(head->next==NULL) // IF the list contained only one item and that was head. So head->next is NULL
            tail = NULL; // 1st node is deleted so list is empty. head and tail both are NULL
        else
            head->next->previous = NULL;

        return;
    }

    node *temp = (node*) malloc(sizeof(node));
    node *tempAnother = (node*) malloc(sizeof(node));
    int i = 1;

    temp = head;

    while((i < position) && temp->next!=NULL){ // find the desired node to delete
        temp = temp->next;
        i++;
    }

    if(i == position){ // desired position found

        // temp node will be deleted

        tempAnother = temp->previous;
        tempAnother->next = temp->next;

        if(temp->next==NULL) // desired node is the last node of list
            tail = tempAnother;
        else
            temp->next->previous = tempAnother; // tempAnother is the previous node of temp->next node

        free(temp);
    }
    else
        printf("Desired position does not exist! Position: %d\n", i);

}

// print the list in forward order
void printLinkedListForward()
{
    printf("\nYour updated linked list in FORWARD ORDER:\n");

    node *myList;
    myList = head;

    while(1)
    {
        if(head==NULL || tail==NULL) break;

        printf("%d ", myList->number);

        if(myList==tail) break;

        myList = myList->next;
    }
    puts("\n");
}

// print the list in reverse order
void printLinkedListBackward()
{
    printf("\nYour full linked list in REVERSE ORDER:\n");

    node *myList;
    myList = tail;

    while(1)
    {
        if(head==NULL || tail==NULL) break;

        printf("%d ", myList->number);

        if(myList->previous==NULL) break;

        myList = myList->previous;
    }
    puts("\n");
}

//This function search the value in the list
bool isValueAvailable(int value)
{
    node *p = head;
    while(p != NULL)
    {
        if(p->number == value)
        {
            return true;
        }
        else
        {
            p = p->next;
        }
    }
    return 0;
}
