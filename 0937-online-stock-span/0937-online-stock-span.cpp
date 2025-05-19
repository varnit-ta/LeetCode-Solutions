class StockSpanner {
public:
    stack<vector<int>> stk;
    int i = 0;
    
    int next(int price) {
        int res = 0;

        while (!stk.empty() && stk.top()[0] <= price){ 
            res = i - stk.top()[1] + stk.top()[2];
            stk.pop();
        }

        stk.push({price, i++, res});
        return res + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */