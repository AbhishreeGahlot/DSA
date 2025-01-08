ZigZag Tree Traversal
Difficulty: MediumAccuracy: 54.05%Submissions: 171K+Points: 4
Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.
0(n) o(n)
Examples:

Input:
        1
      /   \
     2      3
    / \    /  \
   4   5  6    7
Output: [1, 3, 2, 4, 5, 6, 7]
Explanation:
For level 1 going left to right, we get traversal as {1}.
For level 2 going right to left, we get traversal as {3,2}.
For level 3 going left to right, we get traversal as {4,5,6,7}.
Merging all this traversals in single array we get {1,3,2,4,5,6,7}.


class Solution {
    public:
    // Function to store the zig-zag order traversal of a tree in a list.
    vector<int> zigZagTraversal(Node* root)
    {
        // Result vector to store the final zig-zag traversal.
        vector<int> result;

        // If the tree is empty, return an empty result.
        if (root == NULL)
            return result;

        // Queue to perform level-order traversal (BFS).
        queue<Node*> q;

        // Start with the root node in the queue.
        q.push(root);

        // Boolean flag to toggle between left-to-right and right-to-left traversal.
        bool leftToRight = true;

        // Process each level of the tree while the queue is not empty.
        while (!q.empty()) {
            
            // Number of nodes at the current level.
            int size = q.size();

            // Temporary vector to store nodes at the current level in proper order.
            vector<int> ans(size);

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++) {
                
                // Get the front node from the queue.
                Node* frontNode = q.front();

                // Remove the node from the queue.
                q.pop();

                // Determine the index for insertion based on the traversal direction.
                int index = leftToRight ? i : size - i - 1;

                // Store the node's value in the temporary vector.
                ans[index] = frontNode->data;

                // If the left child exists, add it to the queue.
                if (frontNode->left)
                    q.push(frontNode->left);

                // If the right child exists, add it to the queue.
                if (frontNode->right)
                    q.push(frontNode->right);
            }

            // Toggle the traversal direction for the next level.
            leftToRight = !leftToRight;

            // Append the current level's values to the result vector.
            for (auto i : ans) {
                result.push_back(i);
            }
        }

        // Return the final zig-zag traversal result.
        return result;
    }
};
