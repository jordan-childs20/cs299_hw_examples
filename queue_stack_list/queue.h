#include "stack.h"
#ifndef quedef
#define quedef
class queue
{
    public:
        queue(int size);
        ~queue();
        int enqueue(student & student_to_add);
        int dequeue(student & stidnet_to_add);
        int display();

    private:
        int front;
        int back;
        int number_of_items;
        int size_of_queue;
        student * studentQueue;

};
#endif