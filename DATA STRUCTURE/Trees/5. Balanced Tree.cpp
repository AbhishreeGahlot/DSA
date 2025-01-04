Balanced Tree Check
Difficulty: EasyAccuracy: 43.15%Submissions: 323K+Points: 2
Given a binary tree, determine if it is height-balanced. A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.
Time Complexity: O(n)Auxiliary Space: O(h)

Examples:

Input: root[] = [1, 2, N, N, 3]
      1
    /
   2
    \
     3 
Output: false
Explanation: The height difference between the left and right subtrees at node 1 is 2, which exceeds 1. Hence, the tree is not balanced.
Input: root[] = [10, 20, 30, 40, 60]
       10
     /   \
    20   30 
  /   \
 40   60
Output: true
Explanation: The height difference between the left and right subtrees at all nodes is at most 1. Hence, the tree is balanced.
Input: root[] = [1, 2, 3, 4, N, N, N, 5]
       1
      / \
     2   3
    / 
   4
  /
 5
Output: false
Explanation: The height difference between the left and right subtrees at node 2 is 2, which exceeds 1. Hence, the tree is not balanced.
Constraints:
1 <=number of nodes <= 105
1 <= node->data <= 100

class Solution {
private:

pair<bool,int> isBalancedFast(struct Node* root)
{
    if(root==NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int>ans;
    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);
    
    bool leftans=left.first;
    bool rightans= right.first;
    bool diff= abs(left.second - right.second)<=1;
    ans.second=max(left.second,right.second)+1;
    
    if(leftans && rightans && diff)
    {
        ans.first=true;
    }
    else
    {
        ans.first=false;
    }
    return ans;
    
    
    
}

  public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node* root) {
        // Code here
       return isBalancedFast(root).first;
        
        
        
    }
};
