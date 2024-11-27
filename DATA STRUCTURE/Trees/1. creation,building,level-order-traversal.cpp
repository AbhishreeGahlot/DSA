#include<iostream>
#include<queue>
using namespace std;


//1. creation of node   
class node
{
    public:
    
    int data;
    node* left;
    node* right;

    //constructor

    node(int data)
    {
        this->data=data;
        //initially 
        node* left=NULL;
        node* right=NULL;

    }
    
};

//2. Building a tree

node* buildTree(node* root)
{
cout<<"Enter the data"<<endl;
int data;
cin>>data;
root=new node(data);

if(data==-1)
{
    return NULL;
}

cout<<"enter data for left side of "<<data<<endl;
 root->left=buildTree(root->left); //recursive call

cout<<"enter data for right side of "<<data<<endl;
root->right=buildTree(root->right);

return root;



}



//3. level order traversal
void levelOrderTraversal(node* root)
{
 queue<node*> q;
 q.push(root);
 q.push(NULL);
 while(!q.empty())
 {
    node* temp=q.front();
    q.pop();
    if(temp==NULL)
    {
    cout<<endl;
    if(!q.empty())
    {
        q.push(NULL);
    }
    }

    else
    {
        cout<<temp->data<<" ";
    
    if(temp->left)
    {
        q.push(temp->left);
    }

     if(temp->right)
    {
        q.push(temp->right);
    }
 }
}
}


int main()
{
    node* root=NULL;

    root=buildTree(root);
    cout<<"level order traversal"<<endl;
    levelOrderTraversal(root);
    return 0;
}







