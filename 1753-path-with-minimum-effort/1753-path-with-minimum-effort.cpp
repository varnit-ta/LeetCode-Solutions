#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;

        using T = pair<int, pair<int, int>>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        while (!pq.empty()) {
            auto [effort, pos] = pq.top(); pq.pop();
            auto [x, y] = pos;

            if (x == rows - 1 && y == cols - 1) return effort;

            for (auto [dx, dy] : dir) {
                int newX = x + dx, newY = y + dy;

                if (newX >= 0 && newY >= 0 && newX < rows && newY < cols) {
                    int newEffort = max(effort, abs(heights[newX][newY] - heights[x][y]));
                    if (newEffort < dist[newX][newY]) {
                        dist[newX][newY] = newEffort;
                        pq.push({newEffort, {newX, newY}});
                    }
                }
            }
        }

        return 0;
    }
};
