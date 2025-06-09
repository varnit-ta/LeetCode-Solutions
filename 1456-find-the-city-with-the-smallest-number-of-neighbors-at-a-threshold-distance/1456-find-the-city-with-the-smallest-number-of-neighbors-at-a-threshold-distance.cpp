#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Build adjacency list
        vector<vector<pii>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Function to run Dijkstra from a given source node
        auto dijkstra = [&](int src) -> vector<int> {
            vector<int> dist(n, INT_MAX);
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push({0, src});
            dist[src] = 0;

            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;

                for (auto& [v, wt] : adj[u]) {
                    if (dist[v] > d + wt) {
                        dist[v] = d + wt;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        };

        int minReachable = INT_MAX, resNode = -1;

        // Run Dijkstra from each node
        for (int i = 0; i < n; ++i) {
            vector<int> dist = dijkstra(i);
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[j] <= distanceThreshold) {
                    count++;
                }
            }

            // Choose the node with smallest reachable count, prefer larger index
            if (count <= minReachable) {
                minReachable = count;
                resNode = i;
            }
        }

        return resNode;
    }
};
