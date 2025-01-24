#include<iostream>
#include<string>
using namespace std;
//Function Prototypes
void showValues(int [], int);
void showSum(int [], int);
void showAverage(int [], int);

int main()
{
const int SIZE = 10;
int myArray [SIZE] = {1,2,3,12,5,6,7,8,9,10};
showValues(myArray,SIZE);
showSum(myArray, SIZE);

return 0;
}
//Function showValue
void showValues(int nums[], int size)
{
    for(int i = 0; i < size; i++)
    cout << nums[i] <<endl;
}
//Function showSum
void showSum(int nums[], int size)
{
    double sum;
    for(int i = 0; i < size; i++)
    sum += nums[i];
    cout << "The total sum of the array values is: " << sum <<endl;
}

