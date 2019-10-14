#include "list.h"
#ifndef stk
#define stk
struct student
{
    char * name;
    int student_id;
    ordered_list  class_choices;
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
        int top_index;
        int size_of_table;
        //I use a double pointer because I want to create an array of pointers;
        student * studentStack;

};

int display_student(student & student_to_display, bool display_list=false);
int copy_student(student & copy_from, student & copy_to);

#endif