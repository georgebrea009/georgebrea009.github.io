#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;

void printYear(int, int, int);

int main()
{
    int month, day, year;
    cout <<"Enter a month, day and year: " << endl;
    cin >> month >> day >> year;
    printYear(month, day, year);

    return 0;
}

void printYear(int m, int d, int y)
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