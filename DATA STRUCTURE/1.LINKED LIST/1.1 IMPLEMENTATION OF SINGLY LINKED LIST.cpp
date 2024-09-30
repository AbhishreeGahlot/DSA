#include<iostream>
using namespace std;

class Node
{
public:
int data;
Node* next;


//parameterised constructor
Node(int data)
{
    this->data=data;
    this->next=NULL;
}


};




int main()
{
Node* node1 = new Node(10); //creates a new NODE object with data = 10 "(using constructor)"
cout<<node1 -> data <<endl;
cout<<node1 -> next <<endl;
return 0;

}





//OUTPUT 
10 
0 
