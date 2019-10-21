#include "stack.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace::std;

int display_student(student &student_to_display)
{
    cout<<"Student Name: "<<student_to_display.name<<"\n";
    cout<<"ID Number: "<<student_to_display.student_id<<"\n";
    student_to_display.class_choices.display();
    cout<<"\n";
}

stack::stack(int size)
{
    //My stack is going to be made of an array of student pointers.
    //The sutdentStack is a double pointer so I create an array of pointers;
    max_array_size = size;
    head = NULL;
}

stack::~stack()
{
    stack_node * temp;
    while(head)
    {
        pop();
    }
}

int stack::push(student & student_to_add)
{
   
    //if the head is null or the current nodes array is full, create a new node 
    if(head == NULL || head->top_index == max_array_size)
    {
        stack_node * temp = new stack_node;
        temp->student_array = new student[max_array_size];
        temp->next = head;
        temp->top_index = 0;
        head = temp;

    }

    //add the node to the stack
    copy_student(student_to_add, head->student_array[head->top_index]);
    ++head->top_index;
}

int stack::display()
{
    if(!head)
        return 0;

    stack_node * temp = head;
    while(temp)
    {
        for(int i = temp->top_index; i > 0; i--)
            display_student(temp->student_array[i-1]);
        

        temp = temp->next;
    }
    return 1;
   
}

int stack::pop()
{
    --head->top_index;
    if(head->top_index == 0)
    {
         delete [] head->student_array[head->top_index].name;
         stack_node * temp = head;
         head = head->next;1
         delete []temp->student_array;
         delete temp;
    }
    else
    {
        delete [] head->student_array[head->top_index].name;
    }
    
}

int stack::peek(student & student_to_get)
{
    copy_student(head->student_array[head->top_index - 1], student_to_get);
}


//A function to duplicate a student
int copy_student(student & copy_from, student & copy_to)
{
    copy_to.name = new char[sizeof(copy_from.name)];
    strcpy(copy_to.name, copy_from.name);
    copy_to.student_id = copy_from.student_id;
    copy_from.class_choices.copy(copy_to.class_choices);

} 








