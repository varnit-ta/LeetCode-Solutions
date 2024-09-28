class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        map<pair<int, int>, vector<TreeNode*>> dp;

        function<vector<TreeNode*>(int, int)> generate = [&](int left, int right) -> vector<TreeNode*> {
            vector<TreeNode*> res;
            if (left > right) {
                return {nullptr};
            }
            if (dp.find({left, right}) != dp.end()) {
                return dp[{left, right}];
            }

            for (int i = left; i <= right; i++) {
                for (auto l : generate(left, i - 1)) {
                    for (auto r : generate(i + 1, right)) {
                        TreeNode* root = new TreeNode(i, l, r);
                        res.push_back(root);
                    }
                }
            }

            dp[{left, right}] = res;
            return res;
        };

        return generate(1, n);
    }
};
