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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (!root) return newNode;

        TreeNode* ptr = root;

        while (ptr){
            if (ptr->val < val){ 
                if (!ptr->right) break;
                ptr = ptr->right;
            }
            else {
                if (!ptr->left) break;
                ptr = ptr->left;
            }
        }

        if (ptr->val < val){
            ptr->right = newNode;
        }else{
            ptr->left = newNode;
        }

        return root;
    }
};