#include "list.h"

#include <iostream>
#include <cstring>
using namespace::std;

ordered_list::ordered_list(int size)
{
    size_of_list = size;
    list = new char*[size_of_list];
    for(int i=0; i<size_of_list; i++)
    {
        list[i] = NULL;
    }
}
ordered_list::~ordered_list()
{
    for(int i=0; i<size_of_list; i++)
    {
        delete [] list[i];
    }
    delete [] list;
}
int ordered_list::insert(int position, char * & data_to_insert)
{   
    //check that the positon fits within the list
    if(position > size_of_list)
    {
        return 0;
    }
    if(list[position - 1] != NULL)
    {
        delete [] list[position-1];
    }
    list[position - 1] = new char[sizeof(data_to_insert)];
    strcpy(list[position - 1], data_to_insert);
    return 1;
}

int ordered_list::retrieve(int position, char * & data_to_retreive)
{
    //check if there is anything to get at the postion provided
    if(position > size_of_list || list[position - 1] == NULL)
    {
        return 0;
    }
    data_to_retreive = new char[sizeof(list[position - 1])];
    strcpy(data_to_retreive, list[position - 1]);
    list[position-1] = NULL;
    return 1;
}

int ordered_list::display()
{
    //we want some check for our display to see if all of the nodes are null
    bool all_null = true;
    for(int i=0; i<size_of_list; i++)
    {
        if(list[i] != NULL)
        {
            cout<<"Postion "<<i+1<<": "<<list[i]<<"\n";
            all_null = false;
        }
    }
    if(all_null)
    {
        return 0;
    }
    return 1;
}

int ordered_list::copy(ordered_list  &list_copy_to)
{

    if(list_copy_to.size_of_list < size_of_list)
    {
        return 0;
    }
    for(int i=0; i<size_of_list;i++)
    {
        if(list[i] == NULL)
        {
            list_copy_to.list[i] = NULL;
        }
        else
        {
            list_copy_to.list[i] = new char[sizeof(this->list[i])];
            strcpy(list_copy_to.list[i], this->list[i]);
        }
    }
    return 1;
}