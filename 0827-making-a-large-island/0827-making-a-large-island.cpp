class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }

        int findParent(int node) {
            if (parent[node] != node)
                parent[node] = findParent(parent[node]);
            return parent[node];
        }

        void unite(int a, int b) {
            int pa = findParent(a);
            int pb = findParent(b);
            if (pa == pb) return;

            if (size[pa] < size[pb]) {
                parent[pa] = pb;
                size[pb] += size[pa];
            } else {
                parent[pb] = pa;
                size[pa] += size[pb];
            }
        }
    };

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        auto check = [&](int r, int c) -> bool {
            return r >= 0 && c >= 0 && r < n && c < n;
        };

        int ans = 0;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    for (auto& [dx, dy] : vector<pair<int, int>>{{0, 1}, {1, 0}}) {
                        int newRow = row + dx;
                        int newCol = col + dy;
                        if (check(newRow, newCol) && grid[newRow][newCol] == 1) {
                            dsu.unite(row * n + col, newRow * n + newCol);
                        }
                    }
                }
                ans = max(ans, dsu.size[dsu.findParent(row * n + col)]);
            }
        }

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    unordered_set<int> uniqueIslands;
                    int currSize = 1;

                    for (auto& [dx, dy] : dir) {
                        int newRow = row + dx;
                        int newCol = col + dy;
                        if (check(newRow, newCol) && grid[newRow][newCol] == 1) {
                            int par = dsu.findParent(newRow * n + newCol);
                            if (uniqueIslands.find(par) == uniqueIslands.end()) {
                                currSize += dsu.size[par];
                                uniqueIslands.insert(par);
                            }
                        }
                    }
                    ans = max(ans, currSize);
                }
            }
        }

        return ans;
    }
};
