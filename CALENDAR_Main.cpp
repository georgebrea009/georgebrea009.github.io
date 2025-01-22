//CIS-265_098WB
//George Brea
//Project 13 Date - Main Program File
//Due April 28, 2024
#include "CALENDAR_H.h"
#include <iostream>
using namespace std;

 int main()
 {  
    Date dates;
    int reccmonth;
    int reccday;
    int reccyear;
    //Get Month
    cout <<"\tEnter a date of your choice and select the manner which to display it" << endl;
    cout <<"For a month selection, enter a number berween 1 and 12: ";
    cin >> reccmonth;
    if(reccmonth <= 0 || reccmonth >= 13)
    {
        do
        {
           cout <<"You entered an invalid number. Please enter a number between 1 and 12: ";
           cin  >> reccmonth;
        } while (reccmonth <= 0 || reccmonth >= 13);
        
    }
    //Get Day
    cout <<"For a day of month selection, enter a number berween 1 and 31: ";
    cin >> reccday;
    if(reccday <= 0 || reccday >= 32)
    {
        do
        {
           cout <<"You entered an invalid number. Please enter a number between 1 and 31: ";
           cin  >> reccday;
        } while (reccday <= 0 || reccday >= 32);
        
    }
    //Get Year
    cout <<"For a year selection, enter four digits: ";
    cin >> reccyear;
    
    //Store input in the Class object dates
    dates.setmonth(reccmonth);
    dates.setday(reccday);
    dates.setyear(reccyear);
             
    return 0;
 
 }