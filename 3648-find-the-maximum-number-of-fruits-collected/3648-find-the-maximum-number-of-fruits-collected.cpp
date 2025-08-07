#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr int INF = std::numeric_limits<int>::max();
    int dp[1001][1001];
    int n;

    int f(vector<vector<int>>& fruits, vector<pair<int, int>>& dir, int moves, int x, int y){
        if (x == n-1 && y == n-1)
            return moves == 0 ? 0 : INF;

        if (moves == 0 || x == y)
            return INF;

        if (dp[x][y] != -1)
            return dp[x][y];

        int best = -1;

        for (auto& [dx, dy]: dir) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < n && ny < n){
                int newVal = f(fruits, dir, moves-1, nx, ny);
                if (newVal != INF) best = max(best, newVal);
            }
        }

        return dp[x][y] = (best < 0 ? INF : fruits[x][y] + best);
    }


    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        
        int a = 0;
        for (int i = 0; i < n; i++)
            a += fruits[i][i];

        vector<pair<int, int>> bdir = {{1, -1}, {1, 0}, {1, 1}}, cdir = {{-1, 1}, {0, 1}, {1, 1}};

        memset(dp, -1, sizeof(dp));
        int b = f(fruits, bdir, n-1, 0, n-1);
        memset(dp, -1, sizeof(dp));
        int c = f(fruits, cdir, n-1, n-1, 0);

        cout << a << " " << b << " " << c << "\n";

        return a + b + c;
    }
};

