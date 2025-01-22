//CIS-265_098WB
//George Brea
//Project 9 Phone Number List
//Due March 24, 2024

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    const int UINFO = 11;
    const int INFOLENGTH = 25;
    char PLIST[UINFO][INFOLENGTH] = 
     {"Becky Warren, 555-1223",
"Joe Looney, 555-0097",
"Geri Palmer, 555-8787",
"Lynn Presnell, 555-1212",
"Holly Gaddis, 555-8878",
"Sam Wiggins, 555-0998",
"Bob Kain, 555-8712",
"Tim Haynes, 555-7676",
"Warren Gaddis, 555-9037",
"Jean James, 555-4939",
"Ron Palmer, 555-2783",
};
    char match[INFOLENGTH];
    char *strPtr = nullptr;
    bool nomatch = true;
    
    cout << "Enter the name or partial name of the person you wish to find: ";
    cin.getline(match, INFOLENGTH);

    for (int i = 0; i < UINFO; i++)
    {
        strPtr = strstr(PLIST[i], match);
        if (strPtr != nullptr)
        {
            cout << PLIST[i] <<endl;
            strPtr = nullptr;
            nomatch = false;
        }
        
    }

    if(nomatch == true)
    {
      cout << "The entry you made found no matches." << endl;  
    }
                 
return 0;
}
