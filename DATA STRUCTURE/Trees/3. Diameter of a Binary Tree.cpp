Diameter of a Binary Tree
Difficulty: MediumAccuracy: 47.37%Submissions: 305K+Points: 4
Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between any two nodes in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

class Solution {
private:
    // Function to calculate diameter and height in a single traversal.
    pair<int, int> diameterFast(Node* root) {
        if (root == NULL) {
            return make_pair(0, 0); // {diameter, height}
        }
        
        // Recursive calls to left and right subtrees.
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);
        
        // Diameter options:
        int opt1 = left.first;                     // Diameter in the left subtree
        int opt2 = right.first;                    // Diameter in the right subtree
        int opt3 = left.second + right.second + 1; // Diameter passing through the current node
        
        // Resultant diameter and height.
        pair<int, int> ans;
        ans.first = max(opt1, max(opt2, opt3));    // Maximum diameter
        ans.second = max(left.second, right.second) + 1; // Height of the current subtree
        
        return ans;
    }

public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return diameterFast(root).first - 1; // Subtract 1 to count edges, not nodes.
    }
};
