auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return '$';
}();

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> inNodes(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());

        for (int i = 0; i < prerequisites.size(); i++){
            int a = prerequisites[i][0], b = prerequisites[i][1];
            graph[b].push_back(a);
            inNodes[a]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inNodes[i] == 0){ 
                q.push(i);
                ans.push_back(i);
            }
        }

        while (!q.empty()){
            int node = q.front();
            q.pop();

            for (int neigh: graph[node]){
                inNodes[neigh]--;
                if (inNodes[neigh] == 0){
                    q.push(neigh);
                    ans.push_back(neigh);
                }
            }
        }

        return (ans.size() == numCourses) ? ans : vector<int>();
    }
};