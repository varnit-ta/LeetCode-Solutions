class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;

        vector<vector<char>> buckets(s.size() + 1);
        for (auto& [ch, f] : freq) {
            buckets[f].push_back(ch);
        }

        string result;
        for (int i = s.size(); i >= 1; --i) {
            for (char ch : buckets[i]) {
                result += string(i, ch);
            }
        }

        return result;
    }
};
