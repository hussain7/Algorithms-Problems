
// Distance between two nodes in a binary tree

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include<list>
#include <stack>
#include <vector>
#include <memory>

template <class T>
struct Node
{
    T key;
    Node* left;
    Node* right;
    Node(T key)
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

template<class T>
class BST
{
    Node<T>* root;
    public:
    bool insert(T root);
    void deleteNode(T key);
    void print();

    private:
    void BST<T>::printUtils(Node<T>* root);

};

/*
template <class T>  void BST<T>::deleteNode(T key)
{
    
}
*/

template<class T> bool BST<T>::insert(T key)
{
    if(root == NULL)
    {
        auto treeNode = new Node<int>(key);
        root = treeNode;
        return 0;
    }
    else
    {
        if(key > root->key) // move key to right
        {
            root = root->right;
        }
        else // move to left
        {
            root = root->left;
        }
    }

    return 0;
}

template<class T> void BST<T>::print()
{
    printUtils(root);
}

template<class T> void BST<T>::printUtils(Node<T>* root)
{
    if(root == NULL)
        return;

    std::cout<<" Node "<<root->key<<std::endl;
    printUtils(root->left);
    printUtils(root->right);
}


int _tmain(int argc, _TCHAR* argv[])
{
    auto tree = new BST<int>();
    tree->insert(1);
    tree->insert(5);
    tree->insert(7);
    tree->print();
    delete tree;
}