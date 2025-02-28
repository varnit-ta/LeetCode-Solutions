class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long maxWidth = 1;

        while (!q.empty()){
            long long size = q.size();
            long long minIndex = q.front().second;
            long long left, right;
            
            for (int i = 0; i < size; i ++){
                long long currIndex = q.front().second - minIndex;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0) left = currIndex;
                if (i == size - 1) right = currIndex;

                if (node->left) q.push({node->left, 2 * currIndex + 1});
                if (node->right) q.push({node->right, 2 * currIndex + 2});
            }

            maxWidth = max(maxWidth, right - left + 1);
        }

        return maxWidth;
    }
};