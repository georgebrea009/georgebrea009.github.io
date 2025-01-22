//CIS-265_098WB
//George Brea
//Project 11 Monthly Budget
//Due March 31, 2024
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
//Struct
struct MonthlyBudget
{
    double hsng, utils, hsngExpns, trnsprt, food, med, ins, entmnt, clth, misc; 
};
//Function Prototypes
void getMonthCosts(MonthlyBudget &);
void compareCosts(MonthlyBudget &);
//Main
int main()
{
    MonthlyBudget expnsBudget;
    getMonthCosts(expnsBudget);
    compareCosts(expnsBudget);
    return 0;
}
//Function getMonthCosts
void getMonthCosts(MonthlyBudget &d)
{
    cout << "Please enter the dollar and cents amounts, spent on each of these expenses for this month: " << endl;
    cout << "Housing: ";
    cin  >> d.hsng;
    cout << "Utilities: ";
    cin  >> d.utils;
    cout << "House Hold Expenses: ";
    cin  >> d.hsngExpns;
    cout << "Transportation: ";
    cin  >> d.trnsprt;
    cout << "Food: ";
    cin  >> d.food;
    cout << "Medical: ";
    cin  >> d.med;
    cout << "Insurance: ";
    cin  >> d.ins;
    cout << "Entertainment: ";
    cin  >> d.entmnt;
    cout << "Clothing: ";
    cin  >> d.clth;
    cout << "Miscellaneous: ";
    cin  >> d.misc;
           
}
//Function compareCosts
void compareCosts(MonthlyBudget &ec)
{
    MonthlyBudget fc;
    fc = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00};
    double diff, counter = 0, ect;
    double fct = fc.clth+fc.entmnt+fc.food+fc.hsng+fc.hsngExpns+fc.ins+fc.med+fc.misc+fc.trnsprt+fc.utils;
    cout << "\nHere is your expense analysis for this month against your budget: " << endl;
    //Housing
    diff = abs(fc.hsng - ec.hsng);
    counter += diff;
    if(fc.hsng > ec.hsng)
    {
        cout << fixed << showpoint << setprecision(2);
        cout <<"\tSaved $" << diff <<" in housing."<< endl;
    }
    else
        cout << fixed << showpoint << setprecision(2);
        cout <<"\tOver-spent $" << diff <<" in housing."<< endl; 
    //Utilities
    diff = abs(fc.utils - ec.utils);
    counter += diff;
    if(fc.utils > ec.utils)
    {
        cout <<"\tSaved $" << diff <<" in Utilities."<< endl;
    }
    else
        cout <<"\tOver-spent $" << diff <<" in Utilities."<< endl; 
    //Housing Expenses
    diff = abs(fc.hsngExpns - ec.hsngExpns);
    counter += diff;
    if(fc.hsngExpns > ec.hsngExpns)
    {
        cout <<"\tSaved $" << diff <<" in Housing Expenses." << endl;
    }
    else
        cout <<"\tOver-spent $" << diff <<" in Housing Expenses." << endl; 
    //Transporation
    diff = abs(fc.trnsprt - ec.trnsprt);
    counter += diff;
    if(fc.trnsprt > ec.trnsprt)
    {
        cout <<"\tSaved $" << diff <<" in Transporation." << endl;
    }
    else
        cout <<"\tOver-spent $" << diff <<" in Transporation." << endl; 
    //Food
    diff = abs(fc.food - ec.food);
    counter += diff;
    if(fc.food > ec.food)
    {
        cout <<"\tSaved $" << diff <<" in Food." << endl;
    }
    else
        cout <<"\tOver-spent $" << diff <<" in Food." << endl; 
    //Medical
    diff = abs(fc.med - ec.med);
    counter += diff;
    if(fc.med > ec.med)
    {
        cout <<"\tSaved $" << diff <<" in Medical." << endl;
    }
    else
        cout <<"\tOver-spent $" << diff <<" in Medical." << endl; 
    //Insurance
    diff = abs(fc.ins - ec.ins);
    counter += diff;
    if(fc.ins > ec.ins)
    {
        cout <<"\tSaved $" << diff <<" in Insurance." << endl;
    }
    else
        cout <<"\tOver-spent $" << diff <<" in Insurance." << endl; 
    //Entertainment
    diff = abs(fc.entmnt - ec.entmnt);
    counter += diff;
    if(fc.entmnt > ec.entmnt)
    {
        cout <<"\tSaved $" << diff <<" in Entertainment." << endl;
    }
    else
        cout <<"\tOver-spent $" << diff <<" in Entertainment." << endl; 
    //Clothing
    diff = abs(fc.clth - ec.clth);
    counter += diff;
    if(fc.clth > ec.clth)
    {
        cout <<"\tSaved $" << diff <<" in Clothing." << endl;
    }
    else
        cout <<"\tOver-spent $" << diff <<" in Clothing." << endl; 
    //Miscellaneous
    diff = abs(fc.misc - ec.misc);
    counter += diff;
    if(fc.misc > ec.misc)
    {
        cout <<"\tSaved $" << diff <<" in Miscellaneous." << endl;
    }
    else
        cout <<"\tOver-spent $" << diff <<" in Miscellaneous." << endl; 
    //Monthly Budget Difference
    cout << "\n\nThis is how you made out on your budget for this month: " << endl;
    ect = counter;
    diff = abs(fct-ect);
    if(fct > ect)
    {
        //cout << fixed << showpoint << setprecision(2);
        cout <<"\t You saved $" << diff << " This month.  Congratulations!" << endl;
    }
    else
        
        cout << "\tThe spent $" << diff << " over budget this month.";
    
}