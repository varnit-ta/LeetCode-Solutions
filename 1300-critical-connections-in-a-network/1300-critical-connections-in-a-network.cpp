class Solution {
public:
    vector<int> time, lowest;
    vector<vector<int>> bridges;
    int timer = 0;

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int parent, int node) {
        visited[node] = true;
        time[node] = lowest[node] = timer++;

        for (int neigh : graph[node]) {
            if (neigh == parent) continue;

            if (!visited[neigh]) {
                dfs(graph, visited, node, neigh);
                lowest[node] = min(lowest[node], lowest[neigh]);

                if (lowest[neigh] > time[node]) {
                    bridges.push_back({node, neigh});
                }
            } else {
                lowest[node] = min(lowest[node], time[neigh]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        time.resize(n);
        lowest.resize(n);
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);

        for (auto& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(graph, visited, -1, 0);
        return bridges;
    }
};
