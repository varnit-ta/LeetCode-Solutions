class Solution {
public:
    string frequencySort(string s) {
        map<int, vector<char>> int_to_char;
        map<char, int> char_to_int;

        for (char ch: s) char_to_int[ch]++;
        for (auto it: char_to_int) int_to_char[it.second].push_back(it.first);

        string res;

        for (auto it: int_to_char){
            for (auto el: it.second){
                res += string(it.first, el);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};