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


// insert function 
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


// build tree function  
Node* buildBST( int arr[] , int n )
{
    Node* root = NULL; //INITIALLY

    for(int i = 0 ; i<n ;i++)
    {
        root = insert(root,arr[i]);
    }

    return root; // ✅

}

// searching in bst
bool search(Node* root , int val) //complexity  O(height) ,, average= O(log n)
{
    if(root==NULL)
    {
        return false;
    }

    if(root->data == val)
    {
        return true;
    }

    if( root->data < val){
        return search(root->right , val);
    }

    else{
        return search(root->left , val);
    }

}

int main()
{
    int arr[]={5,1,3,4,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = 7;
    Node* root = buildBST(arr,n);
    cout << (search(root, val) ? "Found\n" : "Not Found\n");


    return 0;
}
