class Solution {
public:
    void bfs(vector<vector<int>>& graph, vector<bool>& visited, int node){
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            for (int i = 0; i < graph.size(); i++){
                if (graph[curr][i] == 1 && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int res = 0;

        for (int i = 0; i < isConnected.size(); i++){
            if (!visited[i]){
                bfs(isConnected, visited, i);
                res++;
            }
        }

        return res;
    }
};