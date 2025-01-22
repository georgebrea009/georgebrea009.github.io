//CIS-265_098WB
//George Brea
//Project 12 Inventory Program
//Due April 21, 2024
#include<iostream>
#include<cstring>
#include<cctype>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

//Structures
struct DataFields
{
    string id;
    double qtyIn, whlCost, rtlCost;
    int dmy;
};

//Function Prototypes - Menu served
void addNewRecord(fstream &, DataFields &);
bool displayRecord(fstream &, DataFields &);
void changeRecord(fstream &, DataFields &);

/*The program should not accept dates that the programmer determines
are unreasonable.*/
//Main
int main()

{
    fstream mainInventory;
    DataFields invRecords;
    int choiceNumber;
        cout << "Welcome to the Acmy Inventory Management System" << endl;
        cout << "Select from the following menu options." << endl;
        cout << "\tEnter 1 to add a new record: " << endl;
        cout << "\tEnter 2 to display an existing record: " << endl;
        cout << "\tEnter 3 to change an existing record: " << endl;
        cin >> choiceNumber;
        if(choiceNumber == 1)
        addNewRecord(mainInventory, invRecords);
        else if(choiceNumber == 2)
        displayRecord(mainInventory, invRecords);
        else if(choiceNumber == 3)
        changeRecord(mainInventory, invRecords);
        else
        {
            do
            {   
                cout << "You entered an invalid menu number.  Please enter a 1 or 2 or 3: " << endl;
                cin >> choiceNumber;
                if(choiceNumber == 1)
                addNewRecord(mainInventory, invRecords);
                else if(choiceNumber == 2)
                displayRecord(mainInventory, invRecords);
                else if(choiceNumber == 3)
                changeRecord(mainInventory, invRecords);
            } 
            while (choiceNumber <=0 || choiceNumber >= 4);
        }
        return 0;
}
//Function addNewRecord
void addNewRecord(fstream &inventory, DataFields &records)
{   
    char next;
    inventory.open("inventory.dat", ios::out | ios::binary);
    
    do
    {
        cout << "Enter the following inventory records.\n" << endl;
        cout << "Item Description: " << endl;
        cin  >> records.id;
        cout << "Quantity on Hand: " << endl;
        cin  >> records.qtyIn;
        if(records.qtyIn <= 0)
        {
            do
            {
                cout << "Please enter a quantity amount that is greater than zero: " << endl;
                cin >> records.qtyIn;
            } while (records.qtyIn <= 0);
        }
        cin.ignore();
        cout << "Wholesale Cost: " << endl;
        cin  >> records.whlCost;
        if(records.whlCost <= 0)
        {
            do
            {
                cout << "Please enter a wholesale cost amount greater than zero: " << endl;
                cin >> records.whlCost;
            } while (records.whlCost <= 0);
        }
        cout << "Retail Cost: " << endl;
        cin  >> records.rtlCost;
        if(records.rtlCost <= 0)
        {
            do
            {
                cout << "Please enter a retail cost amount greater than zero: " << endl;
                cin >> records.rtlCost;
            } while (records.rtlCost <= 0);
        }
        cout << "Date Added to Inventory: " << endl;
        cin  >> records.dmy;

        inventory.write(reinterpret_cast<char *>(&records), sizeof(records));

        cout << "Do you want to enter another record? Enter Y or y to Continue.  N or n to stop. " << endl;
        cin  >> next;
        cin.ignore();
    } while (next == 'Y' || next == 'y');
    inventory.close(); 
      
}

//Function displayRecord
bool displayRecord(fstream &inventory, DataFields &records)
{
    char next;
    inventory.open("inventory.dat", ios::in | ios::binary);
    if(!inventory)
    {
        cout << "There is no file with this name.\n";
        return 0;
    }
    cout <<"Here are the inventory items in our database." << endl;
    inventory.read(reinterpret_cast<char *>(&records), sizeof(records)); 
    
    while(!inventory.eof())
    {
        cout << "Item Description: ";
        cout << records.id << endl;
        cout << "Quantity on Hand: ";
        cout << records.qtyIn << endl;
        cout << "Wholesale Cost: $";
        cout << records.whlCost << endl;
        cout << "Retail Cost: $";
        cout << records.rtlCost << endl;
        cout << "Date Added to Inventory: ";
        cout << records.dmy << endl;

        cout << "\nPress the Enter key to see the next record.\n";
        cin.get(next);

        inventory.read(reinterpret_cast<char *>(&records), sizeof(records));

    }

    cout << "There are no more records in this file." << endl;
    inventory.close();
    return 0;
}

//Function changeRecord 
void changeRecord(fstream &inventory, DataFields &records)
{
    long recordItem;
    inventory.open("inventory.dat", ios::in | ios::out | ios::binary);
    cout <<"Select the record you wish to edit.";
    cin  >> recordItem;
    cout << "\t************************************************" << endl;

    inventory.seekg(recordItem * sizeof(records), ios::beg);
    inventory.read(reinterpret_cast<char *>(&records), sizeof(records)); 
    
        //Records Display
        cout << "Item Description: ";
        cout << records.id << endl;
        cout << "Quantity on Hand: ";
        cout << records.qtyIn << endl;
        cout << "Wholesale Cost: $";
        cout << records.whlCost << endl;
        cout << "Retail Cost: $";
        cout << records.rtlCost << endl;
        cout << "Date Added to Inventory: ";
        cout << records.dmy << endl;

        //Change Data
        cout << "Update the Item Description: " << endl;
        cin  >> records.id;
        cout << "Update the new Quantity on Hand: " << endl;
        cin  >> records.qtyIn;
        cout << "Update the Wholesale Cost: $" << endl;
        cin  >> records.whlCost;
        cout << "Update the Retail Cost: $" << endl;
        cin  >> records.rtlCost;
        cout << "Change the Date Added to Inventory: " << endl;
        cin  >> records.dmy;

        inventory.seekp(recordItem * sizeof(records), ios::beg);

        inventory.write(reinterpret_cast<char *>(&records), sizeof(records));

        inventory.close();
    
}



