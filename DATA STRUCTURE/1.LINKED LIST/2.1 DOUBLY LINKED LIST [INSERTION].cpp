#include<iostream>
using namespace std;

// 1. Defining class for a doubly linked list
class Node {
    public:
    int data;        // Holds the data of the node
    Node *prev;      // Pointer to the previous node in the list
    Node *next;      // Pointer to the next node in the list

    // Constructor to initialize a node with a given value
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

// 2. Function to traverse and print the linked list
void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";  // Print the data of the current node
        temp = temp->next;          // Move to the next node in the list
    }
    cout << endl;
}

// 3. Function to get the length of the linked list
int getLength(Node *head) {
    Node *temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;                      // Increment length for each node
        temp = temp->next;           // Move to the next node in the list
    }
    return len;                     // Return the total length of the list
}

//5. INSERT AT HEAD 
void insertAtHead(Node*& head,int d)
{
 Node* temp = new Node(d); // step 1 create a new temp node 
 temp->next=head; // step 2 temp's next should point to head 
 head->prev=temp; //step 3 head's prev should point to temp
 head=temp; // step 4 updating temp to head 
}

//6. INSERT AT TAIL
void insertAtTail(Node*& tail,int d)
{
Node* temp=new Node(d);
temp-> prev=tail;
tail->next=temp;
}

// 4. Main function
int main() {
    // Dynamically creating the first node with data 101
    Node* node1 = new Node(101);    

    // Setting head to point to the first node
    Node* head = node1;   
    
    Node* tail=node1;
    insertAtHead(head,100);          

    // Printing the list starting from the head
    print(head);

    insertAtTail(tail,102);

    cout<<"after insertion at tail"<<endl;
    print(head);
    // Printing the length of the linked list
    cout << "Length: " << getLength(head) << endl;

    return 0;
}


/*output
100 101 
after insertion at tail
100 101 102 
Length: 3*/
