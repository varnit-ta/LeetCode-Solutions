/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        queue<TreeNode*> q;
        q.push(root);
        string res = "";

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                res += "#,";
            } else {
                res += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return res;
    }

    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return nullptr;

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") {
                curr->left = nullptr;
            } else {
                TreeNode* lft = new TreeNode(stoi(str));
                curr->left = lft;
                q.push(lft);
            }

            getline(s, str, ',');
            if (str == "#") {
                curr->right = nullptr;
            } else {
                TreeNode* rht = new TreeNode(stoi(str));
                curr->right = rht;
                q.push(rht);
            }
        }

        return root;
    }
};