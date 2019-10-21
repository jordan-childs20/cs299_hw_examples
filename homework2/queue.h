#ifndef quedef
#define quedef
#include <iostream>
#include "stack.h"
struct queue_node
{
    student data;
    queue_node * next = NULL;
};
class queue
{
    public:
        queue();
        ~queue();
        int enqueue(student & student_to_add);
        int dequeue(student & stidnet_to_add);
        int dequeue();
        int display();

    private:
        int number_of_items;
        queue_node * last;

};


#endif