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
    int diameter = INT_MIN;

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        check(root);
        return diameter;
    }

    int check(TreeNode* root){
        if (!root) return 0;

        int left = check(root->left);
        int right = check(root->right);

        diameter = max(left + right, diameter);
        return max(left, right) + 1;
    }
};