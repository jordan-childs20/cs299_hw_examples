/**
 * Main Driver for Program
 * Implements all the functionality of the college_life ADT
 * Part of CS299 Assignment 1
 * Jordan Childs
**/

#include "program1.h"
#include <iostream>
#include <cstring>
using namespace::std;

int main(void)  
{
  int menuselection;
  int category_selection;
  int ctn = 1;
  char  hintBuffer[300];
  college_life * infoGiver = new college_life();
  while(ctn)
  {
    menuselection = main_menu();
    
    switch(menuselection)
    {
      case 1:
        category_selection = print_categories();
        cout << "what is the hint you want to add?\n -> ";
        cin.get(hintBuffer, 300, '\n');
        cin.ignore(300, '\n');
        infoGiver->add_hint(category_selection, hintBuffer);
        break;
      case 2:
        category_selection = print_categories();
        infoGiver->display(category_selection);
        break;
      case 3:
        category_selection = print_categories();
        cout << "what is the hint you want to add?\n -> ";
        cin.get(hintBuffer, 300, '\n');
        cin.ignore(300, '\n');
        infoGiver->like(category_selection, hintBuffer);
        break;
      default:
        cout << "That is not a valid menut option, please try agian";
    }
    cout << "Would you like to continue?\n(0) No (1) Yes\n ->";
    cin >> ctn;
    
  }

}
