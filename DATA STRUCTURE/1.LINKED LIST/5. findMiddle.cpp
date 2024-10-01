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

//get length function to calculate length of ll
int getLength(Node* head )
{   int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

// middle function 
Node* findMiddle(Node* head)
{
    int len=getLength(head);
    int ans=len/2;

    Node* temp=head;
    int cnt=0;
    while(cnt<ans)
    {
        temp=temp->next;
        cnt++;

    }
    return temp;
}



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

int main()
{
    // Create the first node (head and tail are the same initially)
    Node* head = new Node(11); // creates a new NODE object with data = 11 (using constructor)
    Node* tail = head;         // Initially, head and tail are the same
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    print(head);
    Node* middle =findMiddle(head);
    cout<<"MIDDLE "<<middle->data<<"\n";
    return 0;
}
