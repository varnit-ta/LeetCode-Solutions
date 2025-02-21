class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        check(root, 0);
        return res;
    }

    void check(TreeNode* root, int level) {
        if (!root) return;

        if (res.size() <= level) res.push_back(vector<int>());
        res[level].push_back(root->val);

        check(root->left, level + 1);
        check(root->right, level + 1);
    }
};
