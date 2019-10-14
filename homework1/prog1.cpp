/**
 * Function/Method definitions for college_life
 * Part of CS299 Assignment1
 * Jordan Childs 
 * 
 **/

#include "program1.h"
#include <iostream>
#include <cstring>
using namespace::std;

/**
 * Constructor
 */
college_life::college_life()
{
    lists[0] = NULL;
    lists[1] = NULL;
    lists[2] = NULL;
}

/**
 * Destructor
*/

college_life::~college_life()
{
  node * temp;
  for(int i; i < 3; i++)
  {
    temp = lists[i];
    while(lists[i] != NULL)
    {
      temp = lists[i];
      lists[i] = lists[i]->next;
      delete [] temp->hint;
      delete temp;
    }
  }
}

/*
    Adds node back to list, in order of likes
    
    @param node* head : Head node of list
    @param newNode : node passed in to add
    
    @return int: 0/1 error checking
*/
int college_life::add_node(node * & head, node * newNode)
{
  if(head == NULL)
  {
    head = newNode;
  }
  //if the node being added has more likes than the head, add new node at the head
  else if(newNode->likes >= head->likes)
  {
    newNode->next = head;
    head = newNode;
  }
  else 
  {
    node * curr = head;
    node * prev = head;

    //find the postion in the LL where the node should be added
    while(curr->next != NULL)
    {
      //once the postion is found, set pointers to and break out of loop
      if(curr->likes <= newNode->likes)
      {
        prev = curr;
        curr = curr->next;
        break;
      }
      prev = curr;
      curr = curr->next;
    }
      //add the new node to the list
      prev->next = newNode;
      newNode->next = curr;
  }
  return 1;
}

/*
   Private helper method for displaying a list.
   @return int: 0/1 error success indicator
*/
int college_life::dsp(node * head)
{
  node * curr = head;
  while(curr != NULL)
  {
    cout<<curr->hint<<"\tLikes:"<<curr->likes<<"\n";
    curr = curr->next;
  }
  return 1;
}

/*
    Removes node from list, and increments like counter. Calls add_node()
    
    @param node* head : Head node of list
    @param string hint : string data field to attach to node
    
    @return int: 0/1 error checking
*/
int college_life::like_priv(node * & head, char hint[])
{
  if(head == NULL)
  {
    return 0;
  } 
  else
  {
    node * curr = head;
    node * prev = head;
    while(curr != NULL)
    {
      if(strcmp(curr->hint, hint) == 0)
      {
        ++curr->likes;
        if (curr != head)
        {
          prev->next = curr->next;
          curr->next = NULL;
          add_node(head, curr);
        }
        break;
      }
      prev = curr;
      curr = curr->next;
    }
  }
  return 0;
}

/*
  Public member function to display an indicated category.
  @param int category: category to display
  @return int: 0/1 Error Checking
*/
int college_life::display(int category)
{
  if(category<1 || category>3)
    return 1;
  dsp(lists[category-1]);
  return 0;
}


/*
  Public member function for liking a hint.
  @param int category: the category that the hint to like is in
  @param int hint: the hint to like
  @return int: (0/1) Error Checking
*/
int college_life::like(int category, char hint[])
{
  if(category<1 || category>3)
    return 1;
  like_priv(lists[category-1], hint);
  return 0;
}

/*
  Public member function for adding a hint to the list.
  @param int category: the category to add the list to
  @param char hint[]: the hint to be added.

  @return int: 0/1 error checking

*/
int college_life::add_hint(int category, char * hint)
{
  node * newNode = new node;
  newNode->hint = new char[sizeof(*hint)];
  strcpy(newNode->hint, hint);
  newNode->likes = 0;
  
  if(category<1 || category>3)
    return 1;
  add_node(lists[category-1], newNode);
  return 0;
}


/*
  Executes the main menu 
  @return int: menu choice
*/
int main_menu()
{
  int selection;
  cout<<"Please select from the following Options:\n";
  cout<<"\t(1)Add a new Hint\n\t(2)Display hints\n\t(3)Like a hint\n";
  cout<<"-> ";
  cin >> selection;
  cin.ignore(300, '\n'); 
  return selection;
}

/*
  Displays categories
  @return: categroie selection
*/
int print_categories()
{
  int selection;
  cout<<"What Category do you want?\n";
  cout<<"\t(1)Materials\n\t(2)Registration\n\t(3)Homework\n-> ";
  cin >> selection;
  cin.ignore(300, '\n'); 
  return selection;
}
