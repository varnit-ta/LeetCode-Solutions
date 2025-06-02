class Solution {
public:
    vector<string> createDiff(string a){
        vector<string> res;
        string alph = "abcdefghijklmnopqrstuvwxyz";

        char rep;
        for (auto& ch: a){
            rep = ch;

            for (auto el: alph){
                ch = el;
                res.push_back(a);
                ch = rep;
            }
        }

        return res;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()){
            auto [str, step] = q.front();
            q.pop();

            if (str == endWord) return step;

            for (auto el: createDiff(str)){
                if (s.find(el) != s.end()){
                    s.erase(el);
                    q.push({el, step + 1});
                }
            }
        }

        return 0;
    }
};