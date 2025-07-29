class Solution {
public:
    class DSU{
        public:
        vector<int> parent, size;

        DSU(int n){
            parent.resize(n + 1, 0);
            size.resize(n + 1, 1);
            for (int i = 0; i < n+1; i++) parent[i] = i;
        }

        int findParent(int node){
            if (parent[node] != node)
                parent[node] = findParent(parent[node]);
            return parent[node];
        }

        bool uniteBySize(int a, int b){
            int pa = findParent(a);
            int pb = findParent(b);

            if (pa == pb) return false;

            if (size[pa] < size[pb]){
                parent[pa] = pb;
                size[pb] += size[pa];
            }else{
                parent[pb] = pa;
                size[pa] += size[pb];
            }

            return true;
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int rows = 0, cols = 0;
        for (auto& node: stones){
            rows = max(rows, node[0]);
            cols = max(cols, node[1]);
        }

        DSU dsu(rows + cols + 1);
        unordered_map<int, int> mp;
        for (auto& node: stones){
            dsu.uniteBySize(node[0], node[1] + rows + 1);
            mp[node[0]] = 1;
            mp[node[1] + rows + 1] = 1;
        }

        int cnt = 0;
        for (auto& el: mp)
            if (dsu.findParent(el.first) == el.first) cnt++;
        
        return stones.size() - cnt;
    }
};