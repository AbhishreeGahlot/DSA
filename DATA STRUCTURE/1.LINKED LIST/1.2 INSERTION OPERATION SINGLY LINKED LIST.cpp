INSERTION TYPES : 
1] AT THE FRONT OF LINKED LIST 
2] AFTER A GIVEN NODE 
3] AT A SPECIFIC POSITION 
4] AT THE END OF LINKED LIST 


1] AT THE FRONT OF LINKED LIST
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    // parameterized constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// INSERTION 1 AT HEAD
void insertAtHead(Node* &head, int d) // d = data
{
    // new node creation
    Node* temp = new Node(d);  // node of Node class
    temp->next = head;  // temp's (next ptr) points to head 
    head = temp;        // assigning head position to temp node 
}

int main()
{
    Node* head = new Node(10); // creates a new NODE object with data = 10 (using constructor)
    cout << "Head node data: " << head->data << endl;
    cout << "Head node next: " << head->next << endl;

    insertAtHead(head, 15); //  pass the head pointer and data
    
    // Printing the new head
    cout << "New head node data: " << head->data << endl;
    cout << "New head node next: " << head->next << endl;

    return 0;
}
  OUTPUT :Head node data: 10
Head node next: 0
New head node data: 15
New head node next: 0x63ee7df23eb0

------------------------------------------------------------------------------------------------------

2] INSERTION AT TAIL :
void insertAtTail(Node* &tail, int d)
{
    // new node create
    Node* temp = new Node(d);
    tail->next = temp;  // Set the next pointer of the current tail to the new node
    tail = temp;        // Update the tail to the new node
}

int main()
{
    // Create the first node (head and tail are the same initially)
    Node* head = new Node(11); // creates a new NODE object with data = 11 (using constructor)
    Node* tail = head;         // Initially, head and tail are the same

    // Insert a new node at the tail
    insertAtTail(tail, 13); // pass the tail pointer and data

    // Printing the new tail node
    cout << "New tail node data: " << tail->data << endl;
    cout << "New tail node next: " << tail->next << endl;  // This should be NULL as it's the last node

    return 0;
}
