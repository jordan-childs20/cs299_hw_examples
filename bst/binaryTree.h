#include<iostream>


struct node 
{
    int data;
    node * left_child = NULL;
    node * right_child = NULL;
};



class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        int insert(int data);
        int remove(int data);
        int display(int order);
        int contains(int data);
    private:
        int rc(node * root, int data);
        int inorder_traversal(node * root);
        int preorder_traversal(node * root);
        int postorder_traversal(node * root);
        int rRemove(node * &root, int data);
        int hasChildren(node * node_to_check);
        int inorderSuccesor(node * root);
        int rInsert(node * & root, int data);
        node * root;
};