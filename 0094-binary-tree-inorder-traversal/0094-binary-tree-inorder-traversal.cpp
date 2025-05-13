class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> res;

        while (curr){
            if (curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* pred = curr->left;

                while (pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }

                if (pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return res;
    }
};