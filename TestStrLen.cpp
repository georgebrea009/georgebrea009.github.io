#include<iostream>
#include<cctype>
#include<cstring>
#include<string>
using namespace std;


int main()
{
int numbers[] = {0, 1, 2, 3, 4 };
int *ptr = numbers;
ptr++;
cout << ptr << " No asteriks " << endl;
cout << *ptr << " with asteriks " << endl;;
return 0;
}




