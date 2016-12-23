// C++ program to count all nodes having k leaves
// in subtree rooted with them

#include "stdafx.h"
#include <iostream>

using namespace std;
 
/* A binary tree node  */
struct Node
{
    int data ;
    struct Node * left, * right ;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node * newNode(int data)
{
    struct Node * node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
// Function to print all nodes having k leaves
int kLeaves(struct Node *ptr,int k)
{
    // calculate length of each branch.
    if(ptr == NULL)
        return 0;
    auto left = kLeaves(ptr->left, k);
    auto right = kLeaves(ptr->right,k);

    if(left + right == k)
        std::cout<<" Node "<<ptr->data<<" has "<<k<<" leaves "<<std::endl;

    return left+right+1;
}
 
// Driver program to run the case
int main()
{
    struct Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(4);
    root->left->left  = newNode(5);
    root->left->right = newNode(6);
    root->left->left->left  = newNode(9);
    root->left->left->right  = newNode(10);
    root->right->right = newNode(8);
    root->right->left  = newNode(7);
    root->right->left->left  = newNode(11);
    root->right->left->right  = newNode(12);
 
    kLeaves(root, 2);
 
    return 0;
}
