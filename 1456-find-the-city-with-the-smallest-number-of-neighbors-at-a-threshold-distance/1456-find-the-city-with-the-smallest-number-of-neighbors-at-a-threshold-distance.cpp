typedef long long ll;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<ll>> graph(n, vector<ll>(n, LLONG_MAX));

        for (auto& edge: edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        for (int i = 0; i < n; i++) graph[i][i] = 0;

        for (int via = 0; via < n; via++){
            for (int i = 0; i < n; i++){
                if (i == via) continue;
                for (int j = 0; j < n; j++){
                    if (j == via) continue;
                    if (graph[i][via] == LLONG_MAX || graph[via][j] == LLONG_MAX) continue;
                    graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
                }
            }
        }

        ll mn = LLONG_MAX, mnNode = 0;
        for (int i = 0; i < n; i++){
            int count = 0;
            for (int j = 0; j < n; j++){
                if (graph[i][j] <= distanceThreshold) count++;
            }
            if (mn >= count){
                mn = count;
                mnNode = i;
            }
        }

        return mnNode;
    }
};