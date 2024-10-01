class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = 0, n = prices.size();
        int l = 0, r = 0;

        while (r < n){
            if (prices[r] < prices[max(0, r - 1)]){
                s += (prices[max(0, r - 1)] - prices[l]);
                l = r;
            }
            r++;
        }

        if (l != r){
            s += (prices[max(0, r - 1)] - prices[l]);
        }

        return s;
    }
};