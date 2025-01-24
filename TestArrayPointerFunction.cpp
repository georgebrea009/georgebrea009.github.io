#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//Function Prototypes
void getSales(double *, int);
double totalSales(double *, int);

int main()
{
    const int QTR = 4;
    double sales[QTR];

    getSales(sales, QTR);
    cout << fixed << showpoint << setprecision(2);
    cout <<"Total sales for Q are $";
    cout << totalSales(sales, QTR) << endl;
    return 0;
}
//Function getSales
void getSales(double *nums, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout <<"Enter the sales figure for the Q"<<endl;
        cout << (i + 1) << ": ";
        cin >> nums[i];
    }
}
//Function TotalSales
double totalSales(double *nums, int size)
{
    double sum = 0.0;
    for(int i = 0; i < size; i++)
    {
        sum += *nums;
        nums++;        
    }
    return sum;
}