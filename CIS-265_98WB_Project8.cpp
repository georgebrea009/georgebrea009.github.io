//CIS-265_98WB
//George Brea
//Project 8 String Length
//Due March 24, 2024

#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;

//Function Prototypes
int stringCount(char *, int);

int main()
{
    const int PHRASE_SIZE = 50;
    char phrase[PHRASE_SIZE];
    cout <<"Hi.  Please enter a short phrase: " <<endl;
    cin.getline(phrase, PHRASE_SIZE);
    cout <<"The total number of characters in your phrase is: " << endl;
    cout << stringCount(phrase, PHRASE_SIZE) << endl;    

return 0;
}

//Function stringCount
int stringCount(char *parray, int size)
{
    int total;
    total = strlen(parray);
    return total;
}

