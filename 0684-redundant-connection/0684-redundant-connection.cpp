class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] != node)
            parent[node] = findParent(parent[node]);

        return parent[node];
    }

    bool unite(int a, int b) {
        int pa = findParent(a), pb = findParent(b);

        if (pa == pb) return false;

        if (size[pa] < size[pb]) {
            parent[pa] = pb;
            size[pb] += size[pa];
        }else{
            parent[pb] = pa;
            size[pa] += size[pb];
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (auto& e: edges) {
            int a = e[0], b = e[1];

            if (!dsu.unite(a, b))
                return e;
        }

        return {};
    }
};