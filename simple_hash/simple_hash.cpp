#include "simple_hash.h"
#include <iostream>
#include <cstring>
using namespace::std;

const int SIZE_OF_TABLE = 11;

simple_hash::simple_hash(int size = SIZE_OF_TABLE)
{
    table_size = size;
    number_of_items = 0;
    //dynamily allocate an array of students. . .this should be a prime number
    table = new node*[table_size];
    for(int i=0; i<table_size; i++)
    {
        table[i]= NULL;
    }
}

simple_hash::~simple_hash()
{
    for(int i=0;i<table_size;i++)
    {
        node * temp;
        while(table[i] != NULL)
        {
            temp = table[i];
            table[i] = table[i]->next;
            delete [] temp->data.name;
            delete temp;
        }
    }
    delete [] table;
}



int simple_hash::insert(student & student_to_add)
{

    //find index by hashing the student's ID Number
    int i = hash(student_to_add.id_number);

    node * newnode = new node;
    
    //add the student to the list
    newnode->data.name = new char[sizeof(student_to_add.name)];
    strcpy(newnode->data.name, student_to_add.name);
    newnode->data.id_number = student_to_add.id_number;

    newnode->next = table[i];
    table[i] = newnode;
    
    number_of_items++;
}


int simple_hash::retrieve(int key, student & student_to_get)
{
    //get index from hsh
    int i = hash(key);
   
    if(table[i] == NULL)
        return 0;

    

    node * curr = table[i];
    
    while(curr != NULL)
    {   
        if(curr->data.id_number == key)
            break;

        curr = curr->next;
    }

    if(curr == NULL)
        return 0;

    student_to_get.name = new char[sizeof(curr->data.name)];
    student_to_get.id_number = curr->data.id_number;
    strcpy(student_to_get.name,curr->data.name);
    return 1;  

}

int simple_hash::hash(int id_number)
{
    int index = id_number % table_size;
    return index;
}


int print_student(student * student_to_print)
{
    cout<<"Name: "<<student_to_print->name<<"\n";
    cout<<"ID:"<<student_to_print->id_number<<"\n";
}