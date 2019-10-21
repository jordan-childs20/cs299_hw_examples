
#ifndef stk
#define stk

#include "list.h"
struct student
{
    char * name;
    int student_id;
    ordered_list  class_choices;
};

struct stack_node
{
    student * student_array;
    int top_index;
    stack_node * next;
};

class stack
{
    public:
        stack();
        stack(int size=10);
        ~stack();
        int pop();
        int push(student & studnet_to_add);
        int peek(student & student_to_add);
        int display();

    private:
        int max_array_size;
        stack_node * head;

};

int display_student(student & student_to_display);
int copy_student(student & copy_from, student & copy_to);
int create_student(student & student_to_Create);
int again();
#endif