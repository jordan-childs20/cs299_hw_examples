#include <iostream>
struct student
{
    char * name = NULL;
    int id_number = 0;
};

struct node
{
    student data;
    node * next = NULL;

};


class simple_hash
{
    public:
        simple_hash(int size);
        ~simple_hash();
        int insert(student & student_to_add);
        int retrieve(int id_number, student &student_to_get);

    private:
        int hash(int student_id);
        int table_size;
        int number_of_items;
        node ** table;
};

int print_student(student * stduent_to_print);