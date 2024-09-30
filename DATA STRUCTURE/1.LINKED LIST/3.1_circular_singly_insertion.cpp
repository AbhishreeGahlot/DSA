#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    // Constructor 
    Node (int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "MEMORY FREED from the node with data " << value << endl;
    }
};

// Function 1: Insertion
void insertNode(Node *&tail, int element, int d)
{   
    // Case 1: Empty list 
    if(tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;  // Circular link
    }
    // Case 2: Non-empty list
    else
    {
        Node *curr = tail;
        
        // Search for the node containing 'element'
        do
        {
            if(curr->data == element)
            {
                break;
            }
            curr = curr->next;
        } while(curr != tail);  // Loop through the circular list

        // Insert the new node after the element node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// Function 2: Traversal and printing
void print(Node *tail)
{
    if(tail == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = tail;

    // Loop through the circular list
    do
    {
        cout <<"-->" <<temp->data << " ";
        temp = temp->next;
    } while(temp != tail);  // Stop when we've completed the loop

    cout << " -->tail "<<temp->data << endl;  // Print the last element (tail)
}

int main()
{   
    Node *tail = NULL;

    // Insert nodes
    insertNode(tail, 0, 101);
    print(tail);

    insertNode(tail, 101, 102);
    print(tail);

    insertNode(tail, 101, 99);
    print(tail);

    return 0;
}
