#include <iostream>
using namespace std;

// Node structure
struct Node {
    char sname[30];
    int sid;
    float sgpa;
    int data;
    Node* next;
};

// Function to create a list if one does not exist
void createList(Node*& head) {
    if (head == nullptr) {
        head = new Node();
        head->data = 0; // Initial value, can be changed as needed
        head->next = nullptr;
        cout << "List created with initial node value: " << head->data << endl;
    } else {
        cout << "List already exists!" << endl;
    }
}

// Function to create a list if one does not exist
/*Node* createList() {
    return nullptr;
}*/

/*// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}*/
// Function to insert a node at the beginning of the linked list - Menu item 2
void addNode(Node*& head) {
    if (head == nullptr) {
        cout << "List does not exist. Please create a list first." << endl;
        return;
    }
    Node* newNode = new Node();
    cin.ignore(); // To ignore the newline character left in the input buffer
    cout << "Please enter the name of the student: ";
    cin.getline(newNode->sname, 30);
    cout << "Please enter the student's ID? (4 digit number between 1000-9999) ";
    cin >> newNode->sid;
    while (newNode->sid < 1000 || newNode->sid > 9999) {
        cout << "You entered an invalid number. Enter a 4 digit student ID: " << endl;
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

// Function to insert a node at the end of the linked list
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the linked list
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Value not found in the list!" << endl;
    } else {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    cout << "Linked list: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to delete the entire linked list
void deleteList(Node*& head) {
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    cout << "The list has been deleted." << endl;
}

int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "1. Create list" << endl;
        cout << "2. Add a Node" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Delete node" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Delete entire list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createList(head);
                break;
            /*case 2:
                cout << "Enter the value to insert at beginning: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;*/
            case 2:
                addNode(head);
                break;
            case 3:
                cout << "Enter the value to insert at end: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 4:
                cout << "Enter the value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                deleteList(head);
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}