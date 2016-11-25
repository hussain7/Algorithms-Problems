
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
    public:
    BST();
    Node<T>* insert(Node<T>* root, T element);
    void deleteNode(T key);
    void printTree();
    Node<T>* getroot();
    Node<T>* lca(T key1, T key2, Node<T>* node = root);
    Node<T>* lcaImproved(T key1, T key2, Node<T>* node = root);

    private:
    void BST<T>::printUtility(Node<T>* root);
    Node<T>* root;
};

template<class T> Node<T>* BST<T>::getroot()
{
    return root;
}

template<class T> BST<T>::BST():root(NULL)
{}

template<class T> Node<T>* BST<T>::lca(T key1, T key2, Node<T>* node)
{
    if(node == NULL)
      return node;

    if(node->key >= key1 && node->key <= key2 || node->key <= key1 && node->key >= key2 )
        return node;
    else if (node->key < key1 && node->key < key2)
    {
        lca(key1, key2, node->right);
    }
    else if(node->key < key1 && node->key < key2)
    {
        lca(key1, key2, node->left);
    }

    return NULL;
}

template<class T> Node<T>* BST<T>::lcaImproved(T key1, T key2, Node<T>* node)
{
    if(node == NULL)
        return node;
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (node->key == key1 && node->key == key2)
        return node;
    // check if left or right subtree have lca
    auto nodeLeft = lcaImproved(key1, key2, node);
    auto nodeRight = lcaImproved(key1, key2, node);
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if(nodeLeft && nodeRight ) return node;

    // Otherwise check if left subtree or right subtree is LCA.
    return nodeLeft ? nodeLeft:nodeRight;
}

template<class T> Node<T>* BST<T>::insert(Node<T>* node, T element)
{
    if(node == NULL)
    {
        node = new Node<int>(element);
        return node;
    }

    if(element > node->key) // move key to right
    {
        node->right = insert(node->right, element);
    }
    else if(element < node->key) // move to left
    {
        node->left = insert(node->left, element);
    }
    return node;
}

template<class T> void BST<T>::printTree()
{
   printUtility(getroot());
}

template<class T> void BST<T>::printUtility(Node<T>* root)
{
    if (root != NULL)
    {
        printUtility(root->left);
        std::cout<<" Node "<<root->key<<std::endl;
        printUtility(root->right);
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    auto tree = new BST<int>();
    auto root = tree->getroot();
    root = tree->insert(root,44);
    tree->insert(root, 3);
    tree->insert(root, 7);
    tree->insert(root, 5);
    tree->insert(root, 12);
    tree->insert(root, 75);
    tree->insert(root, 17);
    tree->insert(root, 37);
    auto lcaNode = tree->lca(3,7,root);
    if(lcaNode != NULL)
    {
        std::cout<<"LCA node "<<lcaNode->key<<std::endl;
    }
}
