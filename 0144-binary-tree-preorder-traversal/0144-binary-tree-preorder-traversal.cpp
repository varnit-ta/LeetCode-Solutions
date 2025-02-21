class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()){
            int size = stk.size();
            
            for (int i = 0; i < size; i++){
                TreeNode* node = stk.top();
                stk.pop();
                res.push_back(node->val);

                if (node->right) stk.push(node->right);
                if (node->left) stk.push(node->left);
            }
        }

        return res;
    }
};