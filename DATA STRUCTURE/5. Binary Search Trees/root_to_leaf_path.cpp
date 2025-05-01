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

// 01 
void printPath(vector<int>&path)
{
    for(int i = 0 ; i<path.size();i++) 
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

// 02
void path_helper(Node* root , vector<int> &path)
{
    if(root==NULL)
    {
        return;
    
    }

    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL)
    {
        printPath(path);
        path.pop_back();
        return;
    }

    path_helper(root->left,path);
    path_helper(root->right,path);
    path.pop_back();
}

void rootToLeaf(Node* root)
{
    vector<int>path;
    path_helper(root,path);
    
}


int main()
{
    int arr[]={8 ,5 , 3, 1, 4,6,10,11,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = buildTree(arr,n);
    rootToLeaf(root);
    return 0;
}   