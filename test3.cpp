#include<iostream>
#include<string>
using namespace std;

int main()
{
const int SIZE = 10;
double sum, avg;
int i, highest, lowest, myArray [SIZE] = {1,2,3,12,5,6,7,8,9,10};
//Find highest number
highest = myArray[0];
for(i = 1; i < SIZE; i++)

{
    if(myArray[i] > highest)
    highest = myArray[i];
}
cout <<"The highest number in this array is: "<< highest <<endl;

//Find lowest number
lowest = myArray[0];
for(i = 1; i < SIZE; i++)

{
    if(myArray[i] < lowest)
    lowest = myArray[i];
}
cout <<"The lowest number in this array is: "<< lowest <<endl;
return 0;
}



