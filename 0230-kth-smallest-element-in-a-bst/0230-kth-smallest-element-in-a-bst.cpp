class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0, minElement = -1;
        inOrder(root, counter, k, minElement);

        return minElement;
    }

    void inOrder(TreeNode* root, int& count, int k, int& minElement){
        if (root){
            inOrder(root->left, count, k, minElement);

            count++;
            if (count == k) {
                minElement = root->val;
                return;
            }

            inOrder(root->right, count, k, minElement);
        }
    }
};