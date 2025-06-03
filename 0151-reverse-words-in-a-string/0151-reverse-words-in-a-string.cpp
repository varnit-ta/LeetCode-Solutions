class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp;

        for (char el : s) {
            if (el != ' ') {
                temp += el;
            } else if (!temp.empty()) {
                words.push_back(temp);
                temp.clear();
            }
        }
        
        if (!temp.empty()) {
            words.push_back(temp);
        }

        reverse(words.begin(), words.end());

        string result;
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) result += ' ';
        }

        return result;
    }
};
