class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, const vector<vector<int>>& queries) {
        int dist = n - 1;
        vector<int> jump(n);
        for (int i = 0; i + 1 < n; ++i) {
            jump[i] = i + 1;
        }
        jump[n-1] = n-1;

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &qr : queries) {
            int u = qr[0], v = qr[1];
            while (jump[u] < v) {
                int nxt = jump[u];
                jump[u] = v;
                u = nxt;
                --dist;
            }
            ans.push_back(dist);
        }
        return ans;
    }
};