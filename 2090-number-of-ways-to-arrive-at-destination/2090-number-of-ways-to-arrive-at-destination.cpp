typedef pair<long long, long long> pii;
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pii>> graph(n);
        
        for (auto& edge : roads) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        vector<long long> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, 0});
        ways[0] = 1;
        dist[0] = 0;

        while (!pq.empty()) {
            auto [len, node] = pq.top();
            pq.pop();

            if (dist[node] < len) continue;

            for (auto& [neigh, weigh] : graph[node]) {
                long long newDist = len + weigh;

                if (dist[neigh] > newDist) {
                    dist[neigh] = newDist;
                    ways[neigh] = ways[node];
                    pq.push({dist[neigh], neigh});
                } else if (dist[neigh] == newDist) {
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};
