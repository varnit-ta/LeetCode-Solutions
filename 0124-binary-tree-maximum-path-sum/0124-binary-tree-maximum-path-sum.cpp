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

        int left = max(0, check(root->left)); 
        int right = max(0, check(root->right));

        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
};
