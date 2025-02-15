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

class BstIterator {
public:
    stack<TreeNode*> stk;
    bool reverse;

    BstIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* node = stk.top();
        stk.pop();

        if (reverse) pushAll(node->left);
        else pushAll(node->right);

        return node->val;
    }

    bool hasNext() {
        return !stk.empty();
    }

private:
    void pushAll(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = reverse ? root->right : root->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BstIterator left(root, false);
        BstIterator right(root, true);

        int leftVal = left.next();
        int rightVal = right.next();

        while (leftVal < rightVal) {
            int sm = leftVal + rightVal;
            if (sm == k) return true;

            if (sm < k) {
                if (left.hasNext()) leftVal = left.next();
                else break;
            } else {
                if (right.hasNext()) rightVal = right.next();
                else break;
            }
        }

        return false;
    }
};
