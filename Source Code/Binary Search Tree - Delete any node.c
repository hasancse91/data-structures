/*
    Binary Search Tree - BST implementation Using C language.
    Delete any node of a BST
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


void insertNode(int value);
void preOrderPrint(node *root);
node * findMinimum(node *root);
node * deleteNode(node *root, int value);

int main()
{
    //Create a BST using: 47 40 54 38 43 49 39 45 44 30 41 70 46 59
    insertNode(47);    insertNode(40);    insertNode(54);
    insertNode(38);    insertNode(43);    insertNode(49);
    insertNode(39);    insertNode(45);    insertNode(44);
    insertNode(30);    insertNode(41);    insertNode(70);
    insertNode(46);    insertNode(59);

    printf("\nPre-Order Tree printing:\n");
    preOrderPrint(root);
    puts("");

    //Delete 43 from created BST
    root = deleteNode(root, 43);

    printf("\nPre-Order Tree printing after deletion:\n");
    preOrderPrint(root);
    puts("");

    return 0;
}


node * deleteNode(node *currentNode, int value)
{
    if(currentNode==NULL) // empty tree
        return NULL;
    else if(value < currentNode->number) // value is less than node's number. so go to left subtree
        currentNode->leftChild = deleteNode(currentNode->leftChild, value);
    else if(value > currentNode->number) // value is greater than node's number. so go to right subtree
        currentNode->rightChild = deleteNode(currentNode->rightChild, value);
    else // node found. Let's delete it!
    {
        //node has no child
        if(currentNode->leftChild == NULL && currentNode->rightChild == NULL)
        {
            currentNode = NULL;
        }
        else if(currentNode->leftChild == NULL) // node has only right child
        {
            currentNode = currentNode->rightChild;
        }
        else if(currentNode->rightChild == NULL) // node has only left child
        {
            currentNode = currentNode->leftChild;
        }
        else // node has two children
        {
            node *tempNode = findMinimum(currentNode->rightChild);
            currentNode->number = tempNode->number;
            currentNode->rightChild = deleteNode(currentNode->rightChild, tempNode->number);
        }

    }

    return currentNode;
}

node * findMinimum(node *currentNode)
{
    if(currentNode->leftChild==NULL)
        return currentNode;

    return findMinimum(currentNode->leftChild);
}

void insertNode(int value)
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
