//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x86

/* Program to find next right of a given key */
#include <iostream>
#include <queue>
using namespace std;
 
// A Binary Tree Node
struct node
{
    struct node *left, *right;
    int key;
};
 
// Utility function to create a new tree node
node* newNode(int key)
{
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to test above functions
void print(node *root)
{
    if(root == nullptr)
        return;
    std::cout<<root->key<<"-";
    print(root->left);
    print(root->right);
    
}

// top down DFS
void converttoMirror(node* root)
{
    if(root == nullptr)
        return;
    
    std::swap(root->left, root->right);
    converttoMirror(root->left);
    converttoMirror(root->right);
      
}

// bottoms up DFS
node* converttoMirrorBottomsUp(node* root)
{
    if(root)
    {
        converttoMirror(root->left);
        converttoMirror(root->right);
        std::swap(root->left, root->right);
    }
    
    return root;
}
//check if the path exuts with a given sum
bool sumExits(node* root, int sum)
{
    if(root == nullptr)
    {
        if(sum ==0)
            return true;
        else
            return false;
    }
    
    return sumExits(root->left, (sum - root->key))|| sumExits(root->right, (sum - root->key));

}



// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
    node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
    print(root);
    converttoMirrorBottomsUp(root);
    std::cout<< std::endl<<"sum " << sumExits(root,16)<<std::endl;
    std::cout<<std::endl;
    print(root);
    return 0;
}
