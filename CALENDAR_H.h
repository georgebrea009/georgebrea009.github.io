//CIS-265_098WB
//George Brea
//Project 13 Date - H File
//Due April 28, 2024
#ifndef CALENDAR_H
#define CALENDAR_H

class Date
{
private:
    int month;
    int day;
    int year;
public:
    int getmonth() const;
    int getday() const;
    int getyear() const;
    void setmonth(int);
    void setday(int);
    void setyear(int);
    void printDate(int, int, int);   
};
#endif

