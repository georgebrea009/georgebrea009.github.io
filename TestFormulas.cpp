#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

//fuction prototype
double multi(double &, double &);

int main()
{
    double a = 600.00, b, diff, factor;
    int choice;
    cout <<"How much did you spend this month: $";
    cin >> b;
    while (b <= 0)
        {
            cout <<"You entered an invalid number.  Try again :";
            cin >> b;
        }
    diff = abs(a-b);
    if(a < b)
        {
            cout <<" You spent: $" << diff <<" over budget" << endl;
        }
    else
        cout <<"You spent: $" << b <<" Only. Not bad.  That was only " << diff <<" under budget" << endl;

    factor = multi(diff, b);
    cout <<" Your triple spend amount would've been: " << factor << endl;
return 0;
}

//function multi
double multi(double &a, double &b)
{
    double total;
    total = a * b;
    return total;
    
}

