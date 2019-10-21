#include "queue.h"
#include <iostream>
#include <cstring>
using namespace::std;

queue::queue()
{
    number_of_items = 0;
    last = NULL;
     
}
queue::~queue()
{
    while(last)
        dequeue();
}


int queue::enqueue(student & student_to_add)
{
   
    queue_node * newNode = new queue_node;
    copy_student(student_to_add, newNode->data);

    if(last == NULL)
    {   
        last = newNode;
        newNode->next = newNode;
    }
    else
    {   
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    number_of_items++; 
    return 1;
}

int queue::dequeue(student &student_to_add)
{
    if(last == NULL)
        return 0;

    queue_node * first = last->next;
    copy_student(first->data, student_to_add);
    if(last->next == last)
    {
        delete [] last->data.name;
        delete last;
        last = NULL;
    }
    else 
    {
        last->next = first->next;
        delete [] first->data.name;
        delete first;
    }  
    --number_of_items;
    return 1;
}

int queue::dequeue()
{
    if(last == NULL)
        return 0;

    queue_node * first = last->next;
  
    if(last->next == last)
    {
        delete [] last->data.name;
        delete last;
        last = NULL;
    }
    else 
    {
        last->next = first->next;
        delete [] first->data.name;
        delete first;
    }  
    --number_of_items;
    return 1;
}

int queue::display()
{   
    if(last == NULL)
        return 0;
    
    cout<<"***Front Of Queue***\n";
   
    queue_node * temp = last->next;
    while(temp != last)
    {
        display_student(temp->data);
        temp = temp->next;
    }
    display_student(temp->data);
    cout<<"***Back of Queue***\n";

}
