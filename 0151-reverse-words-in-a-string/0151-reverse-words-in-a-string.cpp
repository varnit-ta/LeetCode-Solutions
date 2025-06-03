class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string temp;

        for (char el : s) {
            if (el != ' ') {
                temp += el;
            } else if (!temp.empty()) {
                words.push(temp);
                temp.clear();
            }
        }

        if (!temp.empty()) {
            words.push(temp);
        }

        string result;
        while (!words.empty()) {
            result += words.top();
            words.pop();
            if (!words.empty()) result += ' ';
        }

        return result;
    }
};
