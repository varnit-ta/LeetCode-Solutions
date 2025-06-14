#ifdef LOCAL
#else
#define debug(...) 42
#endif

#define ll long long
#define pb emplace_back
#define F first
#define S second
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORD(i, a, b) for (int i = a; i > b; --i)
#define FORR(x, a) for (auto& x : a)

struct Edge {
    int u, v, w, idx;
};

class DSU {
    public:
    vi parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        FOR(i, 0, n + 1) parent[i] = i;
    }

    int findParent(int a) {
        if (parent[a] != a)
            parent[a] = findParent(parent[a]);
        return parent[a];
    }

    bool unite(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);
        if (pa == pb) return false;
        if (size[pa] < size[pb]) {
            parent[pa] = pb;
            size[pb] += size[pa];
        } else {
            parent[pb] = pa;
            size[pa] += size[pb];
        }
        return true;
    }
};

class Solution {
    public:
    vii findCriticalAndPseudoCriticalEdges(int n, vii& edgs) {
        int E = edgs.size();
        vector<Edge> edges;

        FOR(i, 0, E) edges.pb(Edge{edgs[i][0], edgs[i][1], edgs[i][2], i});
        sort(all(edges), [](const Edge& a, const Edge& b) {
            return a.w < b.w;
        });

        auto buildMST = [&](int banned = -1, int forced = -1) -> int {
            DSU dsu(n);
            int total = 0;
            if (forced != -1) {
                const Edge& e = edges[forced];
                if (dsu.unite(e.u, e.v)) total += e.w;
            }

            FOR(i, 0, E) {
                if (i == banned) continue;
                const Edge& e = edges[i];
                if (dsu.unite(e.u, e.v)) total += e.w;
            }

            int count = 0;
            FOR(i, 0, n) if (dsu.findParent(i) == i) ++count;
            return (count == 1) ? total : 1e9;
        };

        int mstLen = buildMST();

        vi crit, pcrit;
        FOR(i, 0, E) {
            if (buildMST(i, -1) > mstLen)
                crit.pb(edges[i].idx);
            else if (buildMST(-1, i) == mstLen)
                pcrit.pb(edges[i].idx);
        }

        return vii{crit, pcrit};
    }
};
