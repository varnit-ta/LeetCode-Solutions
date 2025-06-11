class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++)
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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailToAccount;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                } else {
                    dsu.unite(i, emailToAccount[email]);
                }
            }
        }

        unordered_map<int, set<string>> merged;
        for (auto& [email, idx] : emailToAccount) {
            int root = dsu.findParent(idx);
            merged[root].insert(email);
        }

        vector<vector<string>> ans;
        for (auto& [idx, emails] : merged) {
            vector<string> temp;
            temp.insert(temp.begin(), emails.begin(), emails.end());
            //sort(temp.begin(), temp.end());
            temp.insert(temp.begin(), accounts[idx][0]);
            ans.push_back(temp);
        }

        return ans;
    }
};
