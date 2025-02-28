class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto [node, pos] = todo.front();  // Structured bindings
            todo.pop();

            auto& [x, y] = pos;  // Extract values
            nodes[x][y].insert(node->val);

            if (node->left) todo.push({node->left, {x - 1, y + 1}});
            if (node->right) todo.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> res;
        for (auto& [x, levelMap] : nodes) {
            vector<int> col;
            for (auto& [y, values] : levelMap) {
                col.insert(col.end(), values.begin(), values.end());
            }
            res.push_back(col);
        }

        return res;
    }
};
