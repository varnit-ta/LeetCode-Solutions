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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        if (root->val == key){
            return helper(root);
        }

        TreeNode* ptr = root;

        while (ptr){
            if (ptr->val < key){
                if (ptr->right && ptr->right->val == key){
                    ptr->right = helper(ptr->right);
                    return root;
                }else{
                    ptr = ptr->right;
                }
            }else{
                if (ptr->left && ptr->left->val == key){
                    ptr->left = helper(ptr->left);
                    return root;
                }else{
                    ptr = ptr->left;
                }
            }
        }

        return root;
    }

    TreeNode* helper(TreeNode* root){
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        TreeNode* rightTree = root->right;
        TreeNode* leftsRightmost = findRightMost(root->left);
        leftsRightmost->right = rightTree;

        return root->left;
    }

    TreeNode* findRightMost(TreeNode* root){
        if (root->right) return findRightMost(root->right);
        return root;
    }
};