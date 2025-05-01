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

// validate BSTv helper function
bool validateHelper(Node*root , Node* min , Node* max)
{
    if(root==NULL)
    {
        return true;
    }
    // if not null then check
    if(min!=NULL && root->data < min->data)
    {
        return false;
    }
    if(max!=NULL && root->data > max->data)
    {
        return false;
    }

    //check in left and right subtree 
    return validateHelper(root->left , min, root) && validateHelper(root->right , root   , max);

}

// validate bst
bool validateBST(Node*root)
{
    return validateHelper(root,NULL,NULL);
}


int main()
{
    int arr[]={5,1,3,4,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = buildBST(arr,n);
    cout<<validateBST(root);

    return 0;
}
