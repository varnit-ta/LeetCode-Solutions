class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int last = prices[0], mx = 0;

        for (int i = 1; i < prices.size(); i++){
            if (prices[i] < prices[i-1]){
                mx += prices[i-1] - last;
                last = prices[i];
            }
        }

        mx += prices[prices.size() - 1] - last;

        return mx;
    }
};