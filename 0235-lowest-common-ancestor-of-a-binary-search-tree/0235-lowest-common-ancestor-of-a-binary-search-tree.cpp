class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;

        // If root is greater than both p and q, LCA lies in left subtree
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // If root is smaller than both p and q, LCA lies in right subtree
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // If root is between p and q, it's the LCA
        return root;
    }
};
