// Program to find ceil of a given value in BST
#include "stdafx.h"

#include <iostream>

 
/* A binary tree node has key, left child and right child */
struct node
{
    int key;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the given key and
   NULL left and right  pointers.*/
struct node* newNode(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
// helpful for finding best fit
int Ceil(node *root, int input)
{
    // if the input is is equal to root value return
    if(root == NULL)
        return -1;

    if(root->key == input)
        return root->key;

    // must be in the right
    if(root->key < input)
        return Ceil(root->right, input);

    // now either it is in the left or the root
    int left = Ceil(root->left, input);

    // if left is greater than input.
    if(input < left)
     return left;
    else
     return root->key;

    return -1;
}
 
// Driver program to test above function
int main()
{
    node *root = newNode(8);
 
    root->left = newNode(4);
    root->right = newNode(12);
 
    root->left->left = newNode(2);
    root->left->right = newNode(6);
 
    root->right->left = newNode(10);
    root->right->right = newNode(14);
 
    for(int i = 0; i < 16; i++)
    std::cout<<"Ciel for "<<i<<" is " <<Ceil(root, i)<<std::endl;
 
    return 0;
}
