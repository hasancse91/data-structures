/*
    Binary Search Tree - BST implementation
    Using C language.
    Insert value, search value and traverse the whole Tree
    Programmed by Hasan Abdullah
    Contact: http://hellohasan.com
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    int number;
    struct tree *leftChild;
    struct tree *rightChild;

} node;
node *root=NULL;

void insertNode(int value);
void searchOnTree(int value);
void preOrderPrint(node *rootNode);
void inOrderPrint(node *rootNode);
void postOrderPrint(node *rootNode);

int main()
{

    insertNode(45);
    insertNode(54);
    insertNode(40);
    insertNode(49);
    insertNode(38);
    insertNode(70);
    insertNode(30);
    insertNode(39);
    insertNode(41);
    insertNode(45);
    insertNode(44);

    printf("\nPre-Order Tree printing:\n");
    preOrderPrint(root);
    puts("");

    printf("\nIn-Order Tree printing:\n");
    inOrderPrint(root);
    puts("");

    printf("\nPost-Order Tree printing:\n");
    postOrderPrint(root);
    puts("");

    searchOnTree(70);

    return 0;
}

void insertNode(int value)
{
    node *tempNode;
    node *currentNode;
    node *parentNode;

    tempNode = (node *) malloc(sizeof(node));
    tempNode->number = value;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    //For the very first call
    if(root==NULL)
    {
        root = tempNode;
    }
    else
    {
        currentNode = root;
        parentNode = NULL;
        parentNode->leftChild = NULL;
        parentNode->rightChild = NULL;

        while(1)
        {
            parentNode = currentNode;

            if(value <= parentNode->number)
            {
                currentNode = currentNode->leftChild;

                if(currentNode==NULL)
                {
                    parentNode->leftChild = tempNode;
                    return;
                }
            }
            else
            {
                currentNode = currentNode->rightChild;

                if(currentNode==NULL)
                {
                    parentNode->rightChild = tempNode;
                    return;
                }
            }

        }
    }
}

void searchOnTree(int value)
{
    node *currentNode = root;
    int flag = 0;

    while(1)
    {
        if(value == currentNode->number)
        {
            flag = 1;
            break;
        }
        else if(value<=currentNode->number)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;

        if(currentNode==NULL)
            break;

    }

    if(flag==1)
        printf("\n%d is found on Tree.\n\n", currentNode->number);
    else
        printf("\n%d is not found on Tree.\n\n", value);
}

void preOrderPrint(node *rootNode)
{
    if(rootNode==NULL)
        return;

    printf("%d ", rootNode->number);

    preOrderPrint(rootNode->leftChild);
    preOrderPrint(rootNode->rightChild);
}

void inOrderPrint(node *rootNode)
{
    if(rootNode==NULL)
        return;

    inOrderPrint(rootNode->leftChild);

    printf("%d ", rootNode->number);

    inOrderPrint(rootNode->rightChild);
}

void postOrderPrint(node *rootNode)
{
    if(rootNode==NULL)
        return;

    postOrderPrint(rootNode->leftChild);
    postOrderPrint(rootNode->rightChild);

    printf("%d ", rootNode->number);

}
