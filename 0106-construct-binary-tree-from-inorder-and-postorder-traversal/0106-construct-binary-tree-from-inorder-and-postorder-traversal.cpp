class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd, 
    vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
        if (postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int inLeft = inRoot - inStart;

        root->left = buildTree(postorder, postStart, postStart + inLeft - 1, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(postorder, postStart + inLeft, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};