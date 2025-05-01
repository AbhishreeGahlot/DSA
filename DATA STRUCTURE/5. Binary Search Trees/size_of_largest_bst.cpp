// #include<bits/stdc++.h>
// using namespace std;

// class Node
// {
//     public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val)
//     {
//         data = val;
//         left = right = NULL;
//     }
// };


// // insert function 
// Node* insert(Node* root , int val)
// {
//     // bc
//     if(root==NULL)
//     {
//         root = new Node(val);
//         return root;
//     }

//     if (val < root->data) {
//         root->left = insert(root->left, val);  // ✅ Assign back to root->left
//     } else {
//         root->right = insert(root->right, val);  // ✅ Assign back to root->right
//     }

//     return root; //return updated root 
// }


// // build tree function  
// Node* buildBST( int arr[] , int n )
// {
//     Node* root = NULL; //INITIALLY

//     for(int i = 0 ; i<n ;i++)
//     {
//         root = insert(root,arr[i]);
//     }

//     return root; // ✅

// }

// // 1. info class which contains node data 
// class Info
// {
//     public:
//     bool isBST;
//     int min_val;
//     int max_val;
//     int sz; //size

//     Info(bool isBST , int min , int max , int sz)
//     {
//         this->isBST = isBST; // constructor vali class k usko assign
//         this->min_val = min_val;
//         this->max_val = max_val;
//         this->sz = sz;
//     }
// };

// //2 . function which return largest bst size 
// Info* largestBST(Node* root , int &maxSize)
// {
//     // BASE CASE 
//     if(root==NULL)
//     {
//         return new Info(true , INT_MAX , INT_MIN , 0);
//     }

//     // now if valid root present then 
//     Info* leftInfo = largestBST(root->left , maxSize);
//     Info* rightInfo = largestBST(root->right , maxSize);

//     // now calculate the currminimum and currmax , and curr size of the current node 
//     int currMin = min ( root->data , min(leftInfo->min_val, rightInfo->min_val));
//     int currMax = max ( root->data , max(leftInfo->max_val, rightInfo->max_val));
//     int currSize = leftInfo->sz + rightInfo->sz + 1;


//     // now check the conditions 
//     if(leftInfo->isBST && rightInfo->isBST 
//         && root->data > leftInfo->max_val 
//         && root->data < rightInfo->min_val)
//         {
//             maxSize= max(maxSize , currSize);
//             return new Info(true , currMin , currMax , currSize);
//         }

//     // if fails then return false
//     return new Info(false , currMin , currMax , currSize);


// }




// int main()
// {
//     int maxSize = 0;   // ✅ Declare maxSize inside main

//     int arr[]={50, 30, 60, 5, 45, 70, 20, 65, 80  };
//     int n = sizeof(arr)/sizeof(arr[0]);
//     Node* root = buildBST(arr,n);
//    largestBST(root , maxSize);
//    cout<<maxSize;
//     return 0;
// }
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

class Info {
public:
    bool isBST;
    int min_val;
    int max_val;
    int sz;
    Info(bool isBST, int min_val, int max_val, int sz) {
        this->isBST = isBST;
        this->min_val = min_val;
        this->max_val = max_val;
        this->sz = sz;
    }
};

Info* largestBST(Node* root, int &maxSize) {
    if(root == NULL) {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }
    Info* leftInfo = largestBST(root->left, maxSize);
    Info* rightInfo = largestBST(root->right, maxSize);

    int currMin = min(root->data, min(leftInfo->min_val, rightInfo->min_val));
    int currMax = max(root->data, max(leftInfo->max_val, rightInfo->max_val));
    int currSize = leftInfo->sz + rightInfo->sz + 1;

    if(leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max_val && root->data < rightInfo->min_val) {
        maxSize = max(maxSize, currSize);
        return new Info(true, currMin, currMax, currSize);
    }

    return new Info(false, currMin, currMax, currSize);
}

int main() {
    // manually create a BST
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(5);
    root->left->right = new Node(12);
    root->right->left = new Node(17);
    root->right->right = new Node(25);

    int maxSize = 0;
    largestBST(root, maxSize);

    cout << maxSize;
    return 0;
}
