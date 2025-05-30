class Solution {
public:
    void bfs(vector<int>& dist, vector<int>& edges, int start) {
        int step = 0, node = start;

        while (node != -1 && dist[node] == -1) {
            dist[node] = step++;
            node = edges[node];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        bfs(dist1, edges, node1);
        bfs(dist2, edges, node2);

        int min_of_max = INT_MAX, res = -1;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int mx = max(dist1[i], dist2[i]);

                if (mx < min_of_max) {
                    min_of_max = mx;
                    res = i;
                }
            }
        }

        return res;
    }
};
