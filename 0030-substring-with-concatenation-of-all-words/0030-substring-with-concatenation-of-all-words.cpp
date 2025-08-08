class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        int len = s.length();
        int wordLen = words[0].length();
        int wordsNum = words.size();
        int totalLen = wordLen * wordsNum;
        
        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string, int> windowCount;
            int matched = 0;
            
            for (int i = offset; i <= len - wordLen; i += wordLen) {
                string word = s.substr(i, wordLen);
                
                windowCount[word]++;
                matched++;
                
                if (matched > wordsNum) {
                    string leftWord = s.substr(i - totalLen, wordLen);
                    windowCount[leftWord]--;
                    if (windowCount[leftWord] == 0) {
                        windowCount.erase(leftWord);
                    }
                    matched--;
                }
                
                if (matched == wordsNum && windowCount == wordCount) {
                    result.push_back(i - totalLen + wordLen);
                }
            }
        }
        
        return result;
    }
};