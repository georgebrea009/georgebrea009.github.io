#include <iostream>
using namespace std;

//functin prototypes
double getProduct(int, int);
double getSum(int, int);

int main()

{
    int val1, val2;
    double product, sum;
    
    //Get user input
    cout <<"Enter two numbers between 1 and 10" <<endl;
    cout <<"Enter the first number :\n";
    cin >> val1;
    /*while(val1 < 0 && val1 > 11);
    {
        cout <<"You entered a number outside of the range, please enter a number between 1 and 10 :\n";
        cin >> val1;
    }*/
    cout <<"Enter the second number :\n";
    cin >> val2;
     /*while(0 < val2 && val2 > 10);
    {
        cout <<"You entered a number outside of the range, please enter a number between 1 and 10 :\n";
        cin >> val2;
    }*/
    //call getProduct
    product = getProduct(val1, val2);
    cout << "The product of the numbers you entered is: "<< product << endl;

    //call getSum
    sum = getSum(val1, val2);
    cout <<"\t\tThe sum of the numbers you entered is: " << sum << endl;

    return 0;
}
//Function getProduct
double getProduct(int arg1, int arg2)
{
    double prod;
    prod = (arg1 * arg2);
    return prod;
}
//Function getSum
double getSum(int arg1, int arg2)
{
    double sum;
    sum = (arg1 + arg2);
    return sum;
}