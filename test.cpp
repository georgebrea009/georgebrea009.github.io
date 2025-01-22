#include<iostream>
#include<string>
using namespace std;

int main()
{
//array
const int SIZE = 10;
double sum, avg;
int i = 0, highest, lowest, myArray [SIZE] = {1,2,3,4,5,20,7,8,9,10};
for(i = 0; i < SIZE; i++)
{
sum += myArray[i];
avg = sum / SIZE;
}
cout <<"The sum of the numbers in my array is :"<< sum <<endl;
cout <<"The average of the numbers in my array is :"<< avg <<endl;
cout <<"The 3rd postion in this array holds the interger number: "<< myArray[3] <<endl;
for(i = 0; i < SIZE; i++)
{
cout <<myArray[i]++<<endl;
return 0;
}
//get highest number
highest = myArray[0];
for(i = 1; i < SIZE; i++)
{
    if(myArray[i] > highest)
    highest = myArray[i];
}
cout <<"The highest number in this array is: "<< highest <<endl;
return 0;
}



