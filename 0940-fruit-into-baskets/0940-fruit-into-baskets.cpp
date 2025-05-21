class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> mp;
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++){
            mp[fruits[right]]++;

            if (mp.size() <= 2){
                maxLen = max(maxLen, right - left + 1);
            }else{
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }
        }

        return maxLen;
    }
};