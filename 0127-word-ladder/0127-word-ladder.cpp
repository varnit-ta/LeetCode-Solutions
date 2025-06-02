class Solution {
public:
    bool oneCharDiff(string a, string b){
        int diff = 0;
        for (int i = 0; i < a.length(); i++){ 
            diff += (a[i] == b[i] ? 0 : 1);
            if (diff == 2) return false;
        }
        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int vertices = wordList.size() + 1;
        wordList.push_back(beginWord);

        map<string, vector<string>> graph;

        for (int i = 0; i < vertices; i++){
            for (int j = i + 1; j < vertices; j++){
                if (oneCharDiff(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        int step = 0;
        queue<string> q;
        q.push(beginWord);

        set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()){
            int size = q.size();
            step++;

            for (int i = 0; i < size; i++){
                string curr = q.front();
                q.pop();

                if (curr == endWord) return step;

                for (auto neigh: graph[curr]){
                    if (visited.find(neigh) == visited.end()) {
                        q.push(neigh);
                        visited.insert(neigh);
                    }
                }
            }
        }

        return 0;
    }
};