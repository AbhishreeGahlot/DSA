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



// INSERTION AT TAIL
void insertAtTail(Node* &tail, int d)
{
    // new node create
    Node* temp = new Node(d);
    tail->next = temp;  // Set the next pointer of the current tail to the new node
    tail = temp;        // Update the tail to the new node
}

// print 
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";  // Print the data of the current node
        temp = temp->next;          // Move to the next node in the list
    }
    cout << endl;
}

// Function to reverse a linked list
Node* reverse(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    // Iteratively reverse the list
    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev; // New head of the reversed list
}
int main()
{
    // Create the first node (head and tail are the same initially)
    Node* head = new Node(11); // creates a new NODE object with data = 11 (using constructor)
    Node* tail = head;         // Initially, head and tail are the same
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    print(head);
    cout<<"after reversing \n";
    head = reverse(head);
    print(head);
    return 0;
}




//output 
11 12 13 
after reversing 
13 12 11 
