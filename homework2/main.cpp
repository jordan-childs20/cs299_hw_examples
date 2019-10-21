#include "stack.h"
#include "queue.h"
#include <iostream>
#include <cstring>
using namespace::std;
int main(void)
{
    stack keepGroup(5);
    stack rejectGroup(5);
    queue newStudentQueue;

    
    char * names[] = {"Student #1", "Student #2", "Student #3", "Student #4", "Student #5", "Student #6", "Student #7", "Student #8", "Student #9", "Student #10"};
    int   idNums[] = {102098, 102094, 102065, 102045, 102028, 102077, 102008, 102027, 102077, 102046};
    char * classes[] = {"Bilogy", "Chemistry", "Computer Science", "History", "Philosophy", "Psyhcology", "English" };
    student newStudent;
    newStudent.name = NULL;
    for(int i=0;i<10;i++)
    {
        if(newStudent.name != NULL)
        {
            delete [] newStudent.name;
        }

        newStudent.name = new char[sizeof(names[i])];
        strcpy(newStudent.name, names[i]);
        newStudent.student_id = idNums[i];
        for(int j=0; j<3; j++)
        {
            newStudent.class_choices.insert(j+1, classes[rand()%7]);
        } 
        newStudentQueue.enqueue(newStudent);
    }
    cout << "Welcome to Student Portal!\n\n"
         << "What would you like to do?\n";
    int ctn = 1;
    int choice;
    student tempStudent;
    while(ctn)
    {
        cout << "(1) Review Next Student\n"
             << "(2) Display Students Left\n"
             << "(3) Display Accepted Students\n"
             << "(4) Display Rejected Students\n"
             << "(5) Check last accepted student\n"
             << "(6) Check last rejected student\n"
             << "(7) Add Student\n-$ ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                newStudentQueue.dequeue(tempStudent);
                display_student(tempStudent);
                int rejec_status;
                cout<<"Would you like to keep or reject this student?\n 1 -yes  2-no\n-$ ";
                cin >> rejec_status;
                switch(rejec_status)
                {
                    case 1:
                        keepGroup.push(tempStudent);
                        delete [] tempStudent.name;
                        break;
                    case 2:
                        rejectGroup.push(tempStudent);
                        delete [] tempStudent.name;
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                newStudentQueue.display();
                break;
            case 3:
                if(!keepGroup.display())
                    cout<<"No Students accepted yet.";
                break;
            case 4:
                if(!rejectGroup.display())
                    cout<<"No students rejected yet.";
                break;
            case 5:
                if(!keepGroup.peek(tempStudent))
                    cout<<"No Students accepted yet";
                else
                {
                    display_student(tempStudent);   
                }
                break;
            case 6:
                if(!rejectGroup.peek(tempStudent))
                    cout <<"No students rejected yet.";
                else
                {
                    display_student(tempStudent);
                }
            case 7:
                create_student(tempStudent);
                newStudentQueue.enqueue(tempStudent);
                delete [] tempStudent.name;
                
        }

        ctn = again();

    }

    delete [] newStudent.name;
} 

int create_student(student &student_to_create)
{

    //get student name
    char  buffer[200];
    int id_num;
    cout<<"\n\nstudent name: ";
    cin.ignore(300, '\n');
    cin.get(buffer, 300, '\n');
    student_to_create.name = new char[sizeof(buffer)];
    strcpy(student_to_create.name, buffer);
    //get id number
    cin.clear();
    cout<<"id_number: ";
    cin >> id_num;
    student_to_create.student_id = id_num;
    //get class choices
    cout<<"How many classes would you like to imput? (maximum 10)\n-$ ";
    int numClasses;
    cin.clear();
    cin >> numClasses;
    if(numClasses > 10)
        numClasses = 10;
    char * newClass = NULL;
    for(int i = 0; i < numClasses; i++)
    {
        char classBuffer[300];
        cout << "class "<<i+1<<" name"<<"\n-$ ";
        cin.ignore(300, '\n');
        cin.get(classBuffer, 300, '\n');
        char * newClass = new char[sizeof(classBuffer)];
        strcpy (newClass, classBuffer);
        student_to_create.class_choices.insert(i+1, newClass);
        delete [] newClass;
        cin.clear();
    }
    display_student(student_to_create);
}

int again()
{
    int return_val;
    cout<<"\n\nWould You Like To Continue?\n"
        <<"1 - yes   0 - no, quit\n-$ ";
    cin >> return_val;
    cout<<flush;
    return return_val;
}