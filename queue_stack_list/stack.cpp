#include "stack.h"
#include <iostream>
#include <cstring>
using namespace::std;

int display_student(student &student_to_display, bool display_list)
{
    cout<<"Sutdent Name: "<<student_to_display.name<<"\n";
    cout<<"ID Number: "<<student_to_display.student_id<<"\n";
    if(display_list)
        student_to_display.class_choices.display();
    cout<<"\n";
}

stack::stack(int size)
{
    //My stack is going to be made of an array of student pointers.
    //The sutdentStack is a double pointer so I create an array of pointers;
    size_of_table = size;
    studentStack = new student[size_of_table];
    top_index = 0;
}

stack::~stack()
{
    for(int i=0; i<top_index; i++) 
    {   
        delete [] studentStack[i].name;
    }
    delete [] studentStack;
}

int stack::push(student & student_to_add)
{
    //return error condition if stack is full 
    if(top_index == size_of_table)
    {
        return 0;
    }
    //create a new student on the heap
    copy_student(student_to_add, studentStack[top_index]);
    //add the student to the stack
    ++top_index;
}

int stack::display()
{
    int temp = top_index;
    --temp;
    cout<<"***TOP OF STACK***\n";
    while(temp>=0)
    {
        display_student(studentStack[temp]);
        --temp;
    }
   
}

int stack::pop()
{
    delete studentStack[top_index].name;
    --top_index;
}

int stack::peek(student & student_to_get)
{
    copy_student(studentStack[top_index - 1], student_to_get);
}


//A function to duplicate a student
int copy_student(student & copy_from, student & copy_to)
{
    copy_to.name = new char[sizeof(copy_from.name)];
    strcpy(copy_to.name, copy_from.name);
    copy_to.student_id = copy_from.student_id;
    copy_from.class_choices.copy(copy_to.class_choices);

} 








