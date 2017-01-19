/*
    Binary Search Tree - BST implementation Using C language.
    Find maximum and minimum value of a BST
    Programmed by Hasan Abdullah
    Contact: http://hellohasan.com
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
    int number;
    struct bst *leftChild;
    struct bst *rightChild;

} node;

node *root = NULL;

node * insertNodeRecursive(node *root, int value);
void insertNodeIterative(int value);
void preOrderPrint(node *root);
node * findMinRecursive(node *root);
node * findMaxRecursive(node *root);
node * findMinIterative(node *root);
node * findMaxIterative(node *root);

int main()
{
    node *minNode, *maxNode;

    //Insert function in Recursive fashion
    root = insertNodeRecursive(root, 45);
    insertNodeRecursive(root, 54);
    insertNodeRecursive(root, 40);
    insertNodeRecursive(root, 49);
    insertNodeRecursive(root, 38);
    insertNodeRecursive(root, 70);

    //Insert function in Iterative fashion
    insertNodeIterative(30);
    insertNodeIterative(39);
    insertNodeIterative(41);
    insertNodeIterative(45);
    insertNodeIterative(44);

    printf("\nPre-Order Tree printing:\n");
    preOrderPrint(root);
    puts("");

    minNode = findMinIterative(root);
    if(minNode!=NULL)
        printf("\n\nMinimum value is: %d\n", minNode->number);
    else
        printf("\n\nTree is empty!\n");

    maxNode = findMaxRecursive(root);
    if(maxNode!=NULL)
        printf("\n\nMaximum value is: %d\n", maxNode->number);
    else
        printf("\n\nTree is empty!\n");

    return 0;
}


node * findMinRecursive(node *root)
{
    if(root->leftChild==NULL)
        return root->number;

    return findMinRecursive(root->leftChild);
}

node * findMaxRecursive(node *root)
{
    if(root->rightChild==NULL)
        return root;

    return findMaxRecursive(root->rightChild);
}

node * findMinIterative(node *root)
{
    if(root==NULL)
        return root;

    while(root->leftChild != NULL)
    {
        root = root->leftChild;
    }

    return root;
}

node * findMaxIterative(node *root)
{
    if(root==NULL)
        return root;

    while(root->rightChild != NULL)
    {
        root = root->rightChild;
    }

    return root;
}


node * insertNodeRecursive(node *newNode, int value)
{
    if(newNode==NULL)
    {
        newNode = (node *) malloc(sizeof(node));

        newNode->number = value;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;

        return newNode;
    }
    else
    {
        if(value <= newNode->number)
            newNode->leftChild = insertNodeRecursive(newNode->leftChild, value);
        else
            newNode->rightChild = insertNodeRecursive(newNode->rightChild, value);

        return newNode;
    }

}

void insertNodeIterative(int value)
{
    node *tempNode;
    node *currentNode;
    node *parentNode;

    tempNode = (node *) malloc(sizeof(node));
    tempNode->number = value;

    //For the very first call
    if(root==NULL)
    {
        root = tempNode;
    }
    else
    {
        currentNode = root;
        parentNode = NULL;

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

void preOrderPrint(node *root)
{
    if(root==NULL)
        return;

    printf("%d ", root->number);

    preOrderPrint(root->leftChild);
    preOrderPrint(root->rightChild);
}
