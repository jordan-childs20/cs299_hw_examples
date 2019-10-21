#ifndef odrlist
#define odrlist

//An absolute ordered list of char*
//If data is inserted at a postion that already contains data, 
//the data in the list will be overwritten!
class ordered_list
{
    public:
        ordered_list(int size=10);
        ~ordered_list();
        int insert(int position, char  * & data_to_insert);
        int retrieve(int position, char * & data_to_retreive);
        int display();
        int copy(ordered_list  &llist_coy_to);
    private:
        int size_of_list;
        char ** list;
};

#endif