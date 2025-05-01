#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root , int val)
{
     // bc
     if(root==NULL)
     {
         root = new Node(val);
         return root;
     }
 
     if (val < root->data) {
         root->left = insert(root->left, val);  // ✅ Assign back to root->left
     } else {
         root->right = insert(root->right, val);  // ✅ Assign back to root->right
     }
 
     return root; //return updated root 
}

Node* buildTree(int arr[] , int n)
{
    Node* root = NULL;
    for(int i = 0 ; i<n  ; i++)
    {
        root = insert(root,arr[i]);
    }
    return root;
}

// function to return range btw start and end
void printRange ( Node*root , int start , int end)
{
    if(root==NULL)
    {
        return;
    }

    if(start <= root->data && root->data <= end)
    {
        cout<<root->data<<" ";
        printRange(root->left , start , end); // to print in sorted order just put the left function above cout . to print in inorder traversal manner 
        printRange(root->right , start , end);
    }

    else if( root->data < start)
    {
        printRange(root->right , start , end);
    }
    else //( root->data > end )
    {
        printRange(root->left  , start , end);
    }
}


int main()
{
    int arr[]={8 ,5 , 3, 1, 4,6,10,11,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = buildTree(arr,n);

    int start = 5 ;
    int end = 12;
    
    printRange(root,start,end);
    cout<<endl;
    return 0;
}