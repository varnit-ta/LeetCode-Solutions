class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> mp;
        int left = 0, maxNum = 0;

        for (int right = 0; right < fruits.size(); right++){
            mp[fruits[right]]++;

            if (mp.size() < 3){
                maxNum = max(maxNum, right - left + 1);
            }else{
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }
        }

        return maxNum;
    }
};