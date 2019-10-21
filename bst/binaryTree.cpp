#include "binaryTree.h"
#include <iostream>
using namespace std;


int BinarySearchTree::rInsert(node * & root, int data_to_add)
{

    if(root == NULL)
    {
        root = new node;
        root->data = data_to_add;
        return 1;
    }
    else if(data_to_add > root->data)
        rInsert(root->right_child, data_to_add);
    else if(data_to_add < root->data)
        rInsert(root->left_child, data_to_add);
    else
        return 0;
    return 1;
}

int BinarySearchTree::inorderSuccesor(node * root)
{
    if(root->left_child == NULL)
    {
        return root->data;
    }
    else
    {
        return inorderSuccesor(root->left_child);
    }
}

int BinarySearchTree::hasChildren(node * node_to_check)
{
    if(node_to_check->left_child == NULL && node_to_check->right_child == NULL)
    {
        return 0;
    }
    else if(node_to_check->left_child != NULL && node_to_check->right_child == NULL)
    {
        return 1;
    }
    else if(node_to_check->left_child == NULL && node_to_check->right_child != NULL)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}


BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    return;
}

int BinarySearchTree::insert(int data)
{
    if(rInsert(root, data))
        return 1;
    else
        return 0;
}

int BinarySearchTree::remove(int data)
{
    rRemove(root, data);
}

int BinarySearchTree::rRemove(node * &root, int data)
{
    if(root == NULL)
        return 0;
    else if(root->data > data)
        rRemove(root->left_child, data);
    else if(root->data < data)
        rRemove(root->right_child, data);
    else
    {
        node * temp;

        switch(hasChildren(root))
        {
            case 0:
                //has no children, just delete node
                delete root;
                root = NULL;
                break;
            case 1:
                //has only a right child
                temp = root->right_child;
                delete root;
                root = temp;
                break;
            case 2:
                //has only a left child
                temp = root->left_child;
                delete root;
                root = temp;
                break;
            case 3:
                int replacement = inorderSuccesor(root);
                root->data = replacement;
                rRemove(root->left_child, replacement);
                break;

                //has two children -- a complex case must find inorder successor and replace

        }
    }        
}

/* 
   Method to display contents of tree
   @param order: 1 - preorder 2 - inorder 3- postorder
   @returns success of operation 0 - failed 1 - success
*/
int BinarySearchTree::display(int order)
{
    switch(order)
    {
        case 1:
            preorder_traversal(root);
            break;
        case 2:
            inorder_traversal(root);
            break;
        case 3:
            postorder_traversal(root);
            break;
        default:
            return 0;
    }
    cout<<"\n";
    return 1;
}

int BinarySearchTree::rc(node * root, int data)
{
    if(root == NULL)
        return false;
    if(data == root->data
        || rc(root->left_child, data) 
        || rc(root->right_child, data))
        return true;
    else
    {
        return false;
    }
    

}


int BinarySearchTree::contains(int data)
{
    if(rc(root, data))
        return 1;
    else
    {
        return 0;
    }
    
}   

int BinarySearchTree::inorder_traversal(node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    inorder_traversal(root->left_child);
    cout<<root->data<<" - ";
    inorder_traversal(root->right_child);
    return 1;
}

int BinarySearchTree::postorder_traversal(node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    inorder_traversal(root->left_child);
    inorder_traversal(root->right_child);
    cout<<root->data<<" - ";
    return 1;
}

int BinarySearchTree::preorder_traversal(node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    cout<<root->data<<" - ";
    inorder_traversal(root->left_child);
    inorder_traversal(root->right_child);
    return 1;
}




