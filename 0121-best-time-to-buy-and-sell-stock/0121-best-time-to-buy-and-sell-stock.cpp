class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mn = prices[0];

        for (auto i : prices){
            if (i < mn){
                mn = i;
            }else{
                profit = max(profit, i - mn);
            }
        }

        return profit;
    }
};