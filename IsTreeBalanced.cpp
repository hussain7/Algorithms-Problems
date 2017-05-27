#include<stdio.h>
#include <limits.h>
#include <iostream>
#include <cmath> 

/* A tree node structure */
struct node
{
int data;
struct node *left;
struct node *right;
};

int IsBalanced(struct node *root)
{
    if(root == nullptr)
    {
        return 1;
    }
    
    auto left = IsBalanced( root->left);
    auto right = IsBalanced (root->right);
    if(std::abs(left - right) > 1)
        return INT_MAX;
    else
    {
        return std::max(left, right)+1;
    };
}

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
struct node *temp = new struct node;
temp->data = data;
temp->left = NULL;
temp->right = NULL;

return temp;
}

/* Driver function to test above functions */
int main()
{
struct node *root = new struct node;
int k1 = 10, k2 = 25;

/* Constructing tree given in the above figure */
root = newNode(20);
root->left = newNode(8);
root->right = newNode(22);
root->left->left = newNode(4);
root->left->left->left = newNode(3);
auto balanced = false;
if(IsBalanced(root) !=  INT_MAX)
{
    balanced=true;
}

std::cout << "BALANCE !  "<<balanced;

getchar();
return 0;
}
