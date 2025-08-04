class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> reachable;
        for (int i = 1; i < n; i++) {
            reachable.insert(i);
        }

        int steps = n - 1;
        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0], v = q[1];

            auto it = reachable.upper_bound(u);
            
            while (it != reachable.end() && *it < v) {
                it = reachable.erase(it);
                steps--;
            }

            ans.push_back(steps);
        }

        return ans;
    }
};
