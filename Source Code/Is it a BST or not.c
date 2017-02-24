/*
    Check: Is it a Binary Search Tree or Not?
    Implemented by C programming language
    Programmed by Hasan Abdullah
    Contact: http://hellohasan.com
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct bst
{
    int number;
    struct bst *leftChild;
    struct bst *rightChild;

} node;

node *root = NULL;

void insertNode(int value);
void inOrderPrint(node *root);
int isItBst(node *root);
int isItBst_fast(node *root);
int isBstHelper(node *root, int minimum, int maximum);
int isBstInOrderTraversal(node *root, int previous);
int findMin(node *root);
int findMax(node *root);

int main()
{
    int addingItem;
    int previous = INT_MIN;
    //Create a BST using: 47 40 54 38 43 49 39 45 44 30 41 70 46 59
    //In-order output:   30 38 39 40 41 43 44 45 46 47 49 54 59 70
    insertNode(47);    insertNode(40);    insertNode(54);
    insertNode(38);    insertNode(43);    insertNode(49);
    insertNode(39);    insertNode(45);    insertNode(44);
    insertNode(30);    insertNode(41);    insertNode(70);
    insertNode(46);    insertNode(59);


    //In-order output:   30 38 39 40 41 43 44 45 46 47 49 54 59 70
    printf("\nIn-Order Tree printing:\n");
    inOrderPrint(root);
    puts("");


    if(isItBst(root)==1)
        printf("\nSlower Approach:\nYes, it is BST!\n");
    else
        printf("\nSlower Approach:\nNo, it is not BST\n");

    addingItem = 62;
    root->rightChild->number = addingItem;


    //In-order output:   30 38 39 40 41 43 44 45 46 47 49 62 59 70
    printf("\nAfter adding %d as a right child of root.\nIn-Order Tree printing:\n", addingItem);
    inOrderPrint(root);
    puts("");

    if(isItBst_fast(root)==1)
        printf("\nFaster Approach:\nYes, it is BST!\n");
    else
        printf("\nFaster Approach:\nNo, it is not BST\n");


    addingItem = 54;
    root->rightChild->number = addingItem;


    //In-order output:   30 38 39 40 41 43 44 45 46 47 49 54 59 70
    printf("\nAfter adding %d as a right child of root.\nIn-Order Tree printing:\n", addingItem);
    inOrderPrint(root);
    puts("");


    if(isBstInOrderTraversal(root, previous)==1)
        printf("\nIn-order traversal Approach:\nYes, it is BST!\n");
    else
        printf("\nIn-order traversal Approach:\nNo, it is not BST\n");


    return 0;
}


int isItBst_fast(node *root) //Faster way
{
    return (isBstHelper(root, INT_MIN, INT_MAX));
}

int isBstHelper(node *root, int minimum, int maximum)
{
    if(root==NULL)  return 1;

    if((root->number>= minimum && root->number < maximum)
        && isBstHelper(root->leftChild, minimum, root->number)
        && isBstHelper(root->rightChild, root->number, maximum))
        return 1;

    return 0;

    //Same logic but another way
    /*
    if(!(root->number>= minimum && root->number < maximum))
        return 0;
    if(!isBstHelper(root->leftChild, minimum, root->number))
        return 0;
    if(!isBstHelper(root->rightChild, root->number, maximum))
        return 0;

    return 1;
    */
}


int isItBst(node *root) //Not efficient way
{
    if(root==NULL) return 1;

    if(root->leftChild!=NULL && findMax(root->leftChild) > root->number)
        return 0;
    if(root->rightChild!=NULL && findMin(root->rightChild) < root->number)
        return 0;
    if(!isItBst(root->leftChild) || !isItBst(root->rightChild))
        return 0;

    return 1;
}

int findMin(node *root)
{
    if(root->leftChild==NULL)
        return root->number;

    return findMin(root->leftChild);
}

int findMax(node *root)
{
    if(root->rightChild==NULL)
        return root->number;

    return findMax(root->rightChild);
}

int isBstInOrderTraversal(node *root, int previous)
{
    if(root==NULL) return 1; //Base case

    if(!isBstInOrderTraversal(root->leftChild, previous))
        return 0;

    if(root->number < previous)
        return 0;

    previous = root->number;

    return isBstInOrderTraversal(root->rightChild, previous);
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


void inOrderPrint(node *root)
{
    if(root==NULL)
        return;

    inOrderPrint(root->leftChild);

    printf("%d ", root->number);

    inOrderPrint(root->rightChild);
}
