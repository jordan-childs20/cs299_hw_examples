/*  
 * Function and Class declarations for Program 1 
 * Part of CS299 Assignment 1
 * Jordan Childs
 *
 */

#ifndef program1_h
#define program1_h

struct node
{
  char * hint;
  int likes;
  node * next;
};

class college_life
{
  public:
    college_life();
    ~college_life();
    int add_hint(int category, char hint[]);
    int like(int category, char hint[]);
    int display(int category);
  private:
    int add_node(node * & head, node * newNode);
    int dsp(node * head);
    int like_priv(node * & head, char hint[]);
    int order(node * & head);

    node * lists[3];
};

int main_menu();
int print_categories();
#endif


