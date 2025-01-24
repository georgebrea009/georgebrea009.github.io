/*CIS271-B040
Professor Faisal Aljamal
Stack project homework
George Brea
Due: October 18, 2024
*/

#include <iostream>
#include <string>
using namespace std;

//Function Prototype to print the elements of the stack
void PrintStack(int*, int);

//Global Variables for the array size, array name and the top variable value
const int MAX = 7;
int MyStack[MAX];
int top = -1;

//Main function

int main()
{
    int choice, num, i, pop, push, peek, exit;
    
    //Loop for Menu options for user selection and stack operations
    do
    {
        cout << "Hi.  Please select from the following actions." << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Purge" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        //Switch statement for user selection
        switch (choice)
        {
        case 1:
            cout << "Enter a number between 0 and 99 that you want to push: ";
            cin >> push;
            //Loop for validation for user input
            while (push < 0 || push > 99)
            {
                cout <<"Bad entry. Try again. Please select a number between 0 and 99: "<< endl;
                cin >> push;
            }
            //Conditional statement to check if the stack is full and add the number to the stack
            if (top == MAX - 1)
            {
                cout << "Overflow! The stack is full" << endl;
            }
            else
            {
                top++;
                MyStack[top] = push;
                PrintStack(MyStack, MAX);
            }
            break;
        case 2:
            //Conditional statement to check if the stack is empty and pop the number from the stack
            if (top == -1)
            {
                cout << "Underflow! The stack is empty" << endl;
            }
            else
            {
                pop = MyStack[top];
                top--;
                cout << "The number you popped is: " << pop << endl;
                PrintStack(MyStack, MAX);
            }
            break;
        case 3:
            //Conditional statement to check if the stack is empty and show the number at the top the stack
            if (top == -1)
            {
                cout << "Underflow! The stack is empty" << endl;
            }
            else
            {
                peek = MyStack[top];
                cout << "The number on Top is: " << peek << endl;
            }
            break;
        case 4:
            //Conditional statement to check if the stack is empty and to purge the stack
            if (top == -1)
            {
                cout << "Underflow! The stack is empty" << endl;
            }
            else
            {
            top = -1;
            cout << "The stack has been purged" << endl;
            }
            break;
            //Exit the program option and default case for invalid user input
        case 5:
            exit = 1;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (exit != 1);

    return 0;
}

//Function to print the elements of the stack
void PrintStack(int* MStack, int MAX)
{
    int i;
    if (top == -1)
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << "The stack has the following: ";
        for (i = 0; i <= top; i++)
        {
            cout << MStack[i] << " ";
        }
        cout << endl;
    }
}
