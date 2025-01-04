Sum Tree
Difficulty: MediumAccuracy: 37.17%Submissions: 263K+Points: 4
Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.
Time Complexity: O(n)Auxiliary Space: O(log n)
A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Examples:

Input:
    3
  /   \    
 1     2
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
Input:
          10
        /    \
      20      30
    /   \ 
   10    10
Output: false
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
Input:
   25
  /   \    
 9     15
Output: false
Constraints:
2 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

class Solution {
  public:
  
  pair<bool,int> isSumTreeFast(Node *root)
  {
      //base case 1
     if(root==NULL)
     {
         pair<bool,int> p = make_pair(true,0);
         return p;
     }
     // base case 2
     if(root->left==NULL && root->right==NULL)
     {
         pair<bool,int> p = make_pair(true , root->data);
         return p;
     }
     
     //recursive call for left , right
     pair<bool,int> leftAns = isSumTreeFast(root->left);
     pair<bool,int> rightAns = isSumTreeFast(root->right);
     
    bool left=leftAns.first;
    bool right=rightAns.first;
    //condition value caln 
    bool condn=root->data == leftAns.second + rightAns.second;
    
    pair<bool,int>ans;
    
    if(left&&right&&condn)
    {
     ans.first=true;
     //ans.second=2*root->data;
    }
    else
    {
        ans.first=false;
    }
    
    
    
    return ans;
      
      
      
  }
  
  
  
    bool isSumTree(Node* root) {
        // Your code here
    return    isSumTreeFast(root).first;
    }
};
