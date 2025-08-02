class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;

        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]--;

        vector<int> arr;

        for (auto& [num, diff] : freq) {
            if (diff % 2 != 0) return -1;
            for (int i = 0; i < abs(diff) / 2; ++i)
                arr.push_back(num);
        }

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int minVal = *min_element(basket1.begin(), basket1.end());
        minVal = min(minVal, *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < n / 2; ++i) {
            cost += min(arr[i], 2 * minVal);
        }

        return cost;
    }
};
