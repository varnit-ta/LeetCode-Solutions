class Solution {
public:
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        check(root);
        return maxSum;
    }

    int check(TreeNode* root) {
        if (!root) return 0;

        // Recursively compute the max path sum for the left and right subtrees.
        int left = max(0, check(root->left));  // Only add positive contributions from left subtree
        int right = max(0, check(root->right));  // Only add positive contributions from right subtree

        // Update the global maxSum considering the current node's value and both subtrees.
        maxSum = max(maxSum, left + right + root->val);

        // Return the maximum path sum that can be extended to the parent node.
        return max(left, right) + root->val;
    }
};
