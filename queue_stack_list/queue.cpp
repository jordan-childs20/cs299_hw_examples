#include "queue.h"
#include <iostream>
#include <cstring>
using namespace::std;

queue::queue(int size)
{
    size_of_queue = size;
    front = back = number_of_items = 0;
    studentQueue = new student[size_of_queue];  
     
}
queue::~queue()
{
    for(int i=0; i<size_of_queue; i++)
    {
        delete [] studentQueue[i].name;
    }
    delete [] studentQueue;
}


int queue::enqueue(student & student_to_add)
{
    if(number_of_items == size_of_queue)
        return 0;

    copy_student(student_to_add, studentQueue[back]);
    ++number_of_items;
    ++back %= size_of_queue;
}

int queue::dequeue(student &student_to_add)
{
    if(number_of_items == 0)
        return 0;
    
    copy_student(studentQueue[front], student_to_add);
    --number_of_items;
    ++front %= size_of_queue;
}

int queue::display()
{   cout<<"***Front Of Queue***\n";

    for(int i=front; i<back; i++)
        display_student(studentQueue[i]);

    cout<<"***Back of Queue***\n";
}
