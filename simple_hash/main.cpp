#include "simple_hash.h"
#include <iostream>
#include <cstring>
using namespace::std;


int main(void)
{
    simple_hash * hashTable = new simple_hash(11);

    student temp;
    char * array[] = {"Joe","Jill", "James", "Jackson"};
    int  intarr[] = {1234, 5678, 9101112};

    for(int i=0; i<3;i++)
    {
        temp.name = new char[sizeof(array[i])];
        strcpy(temp.name, array[i]);
        temp.id_number = intarr[i];
        hashTable->insert(temp);
        delete [] temp.name;
    }

    hashTable->retrieve(1234, temp);
    cout<<temp.name;
    delete [] temp.name;
    hashTable->retrieve(5678, temp);
    cout<<temp.name;
    delete temp.name;
    delete hashTable;


}


