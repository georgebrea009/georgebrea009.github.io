//CIS-265_098WB
//George Brea
//Project 13 Date - Companion File
//Due April 28, 2024
#include "CALENDAR_H.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Set Month
void Date::setmonth(int m)
{
    if(m >= 1 || m <= 12)
        month = m;
    else
    {
        cout <<"Invalid Input" << endl;
        exit(EXIT_FAILURE);
    }
}
//Set Day
void Date::setday(int d)
{
    if(d >= 1 || d <= 31)
        day = d;
    else
    {
        cout <<"Invalid Input" << endl;
        exit(EXIT_FAILURE);
    }
}
//Set Year
void Date::setyear(int y)
{
    year = y;
}
//Get month day and year
int Date::getmonth() const
{
    return month;
}

int Date::getday() const
{
    return day;
}

int Date::getyear() const
{
    return year;
}
void Date::printDate(int m, int d, int y)
{
    string yearMonth;
    switch (m)
    {
        case 1:
        (yearMonth = "January");
            break;
        case 2:
        (yearMonth = "February");
            break;
        case 3:
        (yearMonth = "March");
            break;
        case 4:
        (yearMonth = "April");
            break;
        case 5:
        (yearMonth = "May");
            break;
        case 6:
        (yearMonth = "June");
            break;
        case 7:
        (yearMonth = "July");
            break;
        case 8:
        (yearMonth = "August");
            break;
        case 9:
        (yearMonth = "September");
            break;
        case 10:
        (yearMonth = "October");
            break;
        case 11:
        (yearMonth = "November");
            break;
        case 12:
        (yearMonth = "December");
            break;
        default:
            break;
        }
    cout << m <<"/"<< d <<"/"<< y % 100 << endl;
    cout << yearMonth <<" "<< d <<" "<< y << endl;
    cout << d <<" "<< yearMonth <<" "<< y << endl;
}
