/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int depth = 1, maxDepth = depth;
        check(root, depth, maxDepth);
        return maxDepth;
    }

    void check(TreeNode* root, int depth, int& maxDepth){
        if (!root) return;

        check(root->left, depth + 1, maxDepth);
        maxDepth = max(depth, maxDepth);
        check(root->right, depth + 1, maxDepth);
    }
};