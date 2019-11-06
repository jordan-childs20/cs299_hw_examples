#include"binaryTree.h"
using namespace std;

int main(void)
{
    BinarySearchTree BST;

    int arr[] = {50, 60, 40, 44, 55, 67, 77, 90, 91, 100, 34, 67, 24, 55};

    for(int i = 0; i<14; i++)
    {
        BST.insert(arr[i]);
    }
    BST.display(1);
      cout <<"\n";
    BST.display(2);
      cout <<"\n";
    BST.display(3);
      cout <<"\n";
    BST.remove(50);
  
    return 0;
}


