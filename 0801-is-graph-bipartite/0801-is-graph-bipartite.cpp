class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int vertices = graph.size();
        vector<int> color(vertices, -1);

        /*
            We can't start from any particular node (say 0th)
            because that would be assuming the graph is fully
            connected.
        */
        for (int i = 0; i < vertices; ++i) {
            if (color[i] == -1) {
                stack<pair<int, int>> stk;
                stk.push({i, 0});
                color[i] = 0;

                while (!stk.empty()) {
                    auto [node, clr] = stk.top();
                    stk.pop();

                    for (auto neigh : graph[node]) {
                        if (color[neigh] == -1) {
                            color[neigh] = (clr == 0 ? 1 : 0);
                            stk.push({neigh, color[neigh]});
                        } else if (clr == color[neigh]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
