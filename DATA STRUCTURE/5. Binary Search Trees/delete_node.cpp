#include<bits/stdc++.h>
using namespace std;

// 1 . user defined structure for tree node
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

// 2. insert function 
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

// 3.  build tree function  
Node* buildBST( int arr[] , int n )
{
    Node* root = NULL; //INITIALLY

    for(int i = 0 ; i<n ;i++)
    {
        root = insert(root,arr[i]);
    }

    return root; // ✅

}


// 4 defintion of : getInorderSuccessor(root->right);
Node* getInorderSuccessor(Node* root)
{
    while(root->left==NULL)
    {
        root = root->left;
    }
    return root;
}

//5 . node to be deleted
Node* delNode(Node* root ,int val) //delete krdo , updated root return kro
{
    if(root==NULL)
    {
        return NULL;
    }

    if(val < root->data)
    {
        root->left = delNode(root->left , val);
    }
    else if ( val > root->data)
    {
        root->right = delNode(root->right , val);
    }
    else  // when val ==root 
    {
        // three cases , here 
        // case 1 : 0 children
        if(root->left == NULL && root->right == NULL )
        {
            delete root;
            return NULL;
        }

        // case 2 : 1 children
        if(root->left == NULL || root->right == NULL )
        {
            return root->left ==NULL ? root->right : root->left;
        }

        // case 3 : 2 children 
        else{
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right ,IS->data); //can be case 0 or case 1 
        }
    }

    return root;
}




// 6 inorder
void inorder(Node* root)
{
    if(root==NULL)
    {
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);


}


int main()
{
    int arr[]={8 ,5 , 3, 1, 4,6,10,11,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = 7; // node to be deleted 
    Node* root = buildBST(arr,n);
    
    inorder(root);
    cout<<endl;

    delNode(root,4);

    inorder(root);
    cout<<endl;



    return 0;
}
