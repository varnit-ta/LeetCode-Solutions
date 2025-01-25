class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        vector<int> first(26, 0), second(26, 0);

        for (int i = 0; i < s.size(); i++){
            first[s[i] - 'a']++;
            second[t[i] - 'a']++;
        }

        return (first == second);
    }
};