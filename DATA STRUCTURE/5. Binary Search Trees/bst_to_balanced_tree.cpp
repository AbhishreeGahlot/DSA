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

void preorder(Node* root)
{
    if(root==NULL)
    {
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}






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

//-------------------------------------------------------------------------------------------------------
//1. inorder sequence function
void getInorder(Node*root , vector<int> &nums)
{
    if(root==NULL)
    {
        return;
    }

    getInorder(root->left , nums);
    nums.push_back(root->data);
    getInorder(root->right , nums);
}

//2. balance tree logic
Node* buildBSTfromSortedVector( vector<int>arr , int st , int end)
{
    if(st > end)
    {
        return NULL;
    }

    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = buildBSTfromSortedVector( arr,st,mid-1);
    curr->right = buildBSTfromSortedVector( arr,mid+1,end);
    return curr;
}


//3. wrap up function
Node* buildBalancedBST(Node* root )
{
    vector<int>nums;
    getInorder(root,nums);

    return buildBSTfromSortedVector(nums , 0 , nums.size()-1);

}

int main()
{
    int arr[]={5,1,3,4,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = buildBST(arr,n);
    cout<<"Preorder before balanced tree"<<endl;
    preorder(root);
    buildBalancedBST(root);
    cout<<endl;
    cout<<"Preorder after balanced tree"<<endl;
    preorder(root);


    return 0;
}