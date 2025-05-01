#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// CODE HERE 
// build tree
Node* buildBSTfromSorted( vector<int>arr , int st , int end)
{
    if(st > end)
    {
        return NULL;
    }

    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = buildBSTfromSorted( arr,st,mid-1);
    curr->right = buildBSTfromSorted( arr,mid+1,end);

    return curr;
}

void getInorder(Node* root , vector<int> &nodes)
{
    if(root==NULL)
    {
        return;
    }

    getInorder(root->left , nodes);
    nodes.push_back(root->data);
    getInorder(root->right , nodes);
}

Node* mergeBST(Node* root1 , Node* root2)
{
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1 , nodes1);
    getInorder(root2 , nodes2 );

    int i = 0 , j = 0 ;
    while(i<nodes1.size() && j<nodes2.size())
    {
        if(nodes1[i]<nodes2[j])
        {
            merged.push_back(nodes1[i]);
            i++;
        }
        else
        {
            merged.push_back(nodes2[j]);
            j++;
        }
    }

    while(i<nodes1.size())
    {
        merged.push_back(nodes1[i]); 
        i++;
    }

    while(j<nodes2.size())
    {
        merged.push_back(nodes2[j]);
        j++;
    } 

    return buildBSTfromSorted( merged,0 , merged.size()-1);
    
}

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

int main() {
    // manually create a BST
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left= new Node(3);
    root2->right = new Node(12);
 
    Node* root = mergeBST(root1 , root2);
    preorder(root);
    cout<<endl;
   

    return 0;
}
