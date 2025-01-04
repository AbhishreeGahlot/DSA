Identical Trees
Difficulty: EasyAccuracy: 50.01%Submissions: 276K+Points: 2
Given two binary trees with their root nodes r1 and r2, return true if both of them are identical, otherwise, false.

Examples:

Input:
    1          1
   /   \       /   \
  2     3    2    3
Output: true
Explanation: 
There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
Input:
    1         1
   /   \      /  \
  2     3   3   2
Output: false
Explanation: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.



tc : o(n)
sc :o(n)


  code: 

  class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        if(r1==NULL && r2==NULL)
        {
            return true;
        }
        
        if(r1==NULL && r2!=NULL)
        {
            return false;
        }
        
        if(r1!=NULL && r2==NULL)
        {
            return false;
        }
        
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        bool currVal=r1->data==r2->data;
        
        if(left&&right&&currVal)
        {
            return true;
    }
    else
    {
        return false;
    }}
};
