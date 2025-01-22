class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string temp = "";

        for (char el : s) {
            if (el != ' ') {
                temp += el;
            } else if (!temp.empty()) { 
                if (!result.empty()) {
                    result = temp + " " + result; 
                } else {
                    result = temp;
                }
                temp = ""; 
            }
        }

        if (!temp.empty()) {
            if (!result.empty()) {
                result = temp + " " + result;
            } else {
                result = temp;
            }
        }

        return result;
    }
};
