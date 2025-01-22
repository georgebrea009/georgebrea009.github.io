#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Node structure with student data
struct Node;
typedef Node* NodePtr;
struct Node {
    char sname[30];
    int sid;
    float sgpa;
    int data;
    NodePtr next;
};
// Function to create an empty list
void createList(Node*& head) {
    if (head == nullptr) {
        head = new Node();
        head->next = nullptr;
        cout << "Empty list created. You can now add nodes." << endl;
    } else {
        cout << "List already exists!" << endl;
    }
}
// Function to check for duplicate student ID
bool checkSID(Node* head, int sid) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->sid == sid) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// Function to insert a node at the beginning of the linked list - Menu item 2
void addNode(Node*& head) {
    if (head == nullptr) {
        cout << "List does not exist. Please create a list first." << endl;
        return;
    }
    Node* newNode = new Node();
    cin.ignore(); 
    cout << "Please enter the name of the student: ";
    cin.getline(newNode->sname, 30);
    cout << "Please enter the student's ID? (4 digit number between 1000-9999) ";
    cin >> newNode->sid;
    while (newNode->sid < 1000 || newNode->sid > 9999 || checkSID(head, newNode->sid)) {
        if (checkSID(head, newNode->sid)) {
            cout << "Student ID already exists. Enter a unique 4 digit student ID: " << endl;
        } else {
            cout << "You entered an invalid number. Enter a 4 digit student ID: " << endl;
        }
        cin >> newNode->sid;
    }
    cout << "Please enter the student's GPA: ";
    cin >> newNode->sgpa;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Move to next link in chain
        }
        temp->next = newNode; // makes the last node point to the new node which points to Null
    }
}
// Function to print the contents of the nodes - Menu item 6
void printList(Node* head) {
    if (head == nullptr) {
        cout << "List does not exist." << endl;
        return;
    }
    cout << "Linked List: " << endl;
    Node* temp = head;
    while (temp != nullptr) {
        
        cout << "  Student Name: " << temp->sname;
        cout << "  Student ID: " << temp->sid;
        cout << fixed << setprecision(2);
        cout << "  Student GPA: " << temp->sgpa << endl;
        temp = temp->next;
    }
}
// Function to purge (delete) all nodes from the list - Menu item 7
void purgeList(Node*& head) {
    if (head == nullptr) {
        cout << "List does not exist." << endl;
        return;
    }
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr; // Reset the head pointer to indicate an empty list
    cout << "All nodes have been deleted. The list is now empty." << endl;
}
// Function to delete a node based on student ID - Menu item 3
void deleteNode(Node*& head, int sid) {
    if (head == nullptr) {
        cout << "List does not exist." << endl;
        return;
    }
    cout << "Enter the student ID to delete: ";
    cin >> sid;
    Node* temp = head;
    Node* prev = nullptr;
    // If the node to be deleted is the head node
    if (temp != nullptr && temp->sid == sid) {
        head = temp->next;
        delete temp;
        cout << "Node with student ID " << sid << " deleted." << endl;
        return;
    }
    // Search for the node to be deleted
    while (temp != nullptr && temp->sid != sid) {
        prev = temp;
        temp = temp->next;
    }
    // If the node was not found
    if (temp == nullptr) {
        cout << "Node with student ID " << sid << " not found." << endl;
        return;
    }
    // Unlink the node from the linked list
    prev->next = temp->next;
    delete temp;
    cout << "Node with student ID " << sid << " deleted." << endl;
}
// Function to modify a node based on student ID - Menu item 4
void modifyNode(Node*& head, int sid) {
    if (head == nullptr) {
        cout << "List does not exist." << endl;
        return;
    }
    cout << "Enter the student ID to modify: ";
    cin >> sid;
    Node* temp = head;
    // Search for the node to be modified
    while (temp != nullptr && temp->sid != sid) {
        temp = temp->next;
    }
    // If the node was not found
    if (temp == nullptr) {
        cout << "Node with student ID " << sid << " not found." << endl;
        return;
    }
    // Modify the data in the node
    cin.ignore();
    cout << "Enter the new name of the student: ";
    cin.getline(temp->sname, 30);
    cout << "Enter the new GPA of the student: ";
    cin >> temp->sgpa;
    cout << "Node with student ID " << sid << " has been modified." << endl;
}
// Function to display a node based on student ID - Menu item 5
void displayNode(Node* head, int sid) {
    if (head == nullptr) {
        cout << "List does not exist." << endl;
        return;
    }
    cout << "Enter the student ID to display: ";
    cin >> sid;
    Node* temp = head;
    // Search for the node to be displayed
    while (temp != nullptr && temp->sid != sid) {
        temp = temp->next;
    }
    // If the node was not found
    if (temp == nullptr) {
        cout << "Node with student ID " << sid << " not found." << endl;
        return;
    }
    // Display the student's data
    cout << " Student Name: " << temp->sname;
    cout << " Student ID: " << temp->sid;
    cout << fixed << setprecision(2);
    cout << " Student GPA: " << temp->sgpa;
    cout << endl;    
}
//Main function of the link list program
int main() {
    Node* head = nullptr;
    int choice, sid;
    do {
        cout << "1. Create list" << endl;
        cout << "2. Add a node" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. Modify a node" << endl;
        cout << "5. Display a node" << endl;
        cout << "6. Display the list" << endl;
        cout << "7. Purge the list" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createList(head);
                break;
            case 2:
                addNode(head);
                break;
            case 3:
                deleteNode(head, sid);
                break;
            case 4:
		        modifyNode(head, sid);
                break;                
            case 5:
 		        displayNode(head, sid);
                break;                
            case 6:
 		        printList(head);
                break;
            case 7:
                purgeList(head);
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}