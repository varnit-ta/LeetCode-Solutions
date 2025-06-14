class Solution {
public:
    /*
    Approach 1:
        If we keep removing the leafs from outside,
        eventually we will reach node/s (1 or 2 nodes)
        that are at the centre of the tree and therefore
        equidistant from all the leafs i.e minimum height

    Approach 2: Diameter + Midpoint Method
        From any leaf node, find the longest path to another
        leaf. Now the middle node in the path will be the
        node required.
    */
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (auto x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);

            indegree[x[0]]++;
            indegree[x[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) 
            if (indegree[i] == 1)
                q.push(i);
        
        int rem = n;

        while (rem > 2){
            int sz = q.size();
            rem -= sz;

            while (sz > 0){
                int node = q.front();
                q.pop();

                for (auto& neigh: graph[node]){
                    if (indegree[neigh] != 0){
                        indegree[neigh]--;

                        if (indegree[neigh] == 1)
                            q.push(neigh);
                    }
                }
                sz--;
            }
        }

        vector<int> ans;
        while (!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};