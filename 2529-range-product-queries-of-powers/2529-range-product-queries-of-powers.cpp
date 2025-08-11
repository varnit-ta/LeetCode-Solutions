class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> powers;
        int p = 0;

        while (n > 0) {
            if (n & 1) powers.push_back(p);
            p++;
            n >>= 1;
        }

        vector<long long> ps(powers.size() + 1, 0);
        for (int i = 0; i < powers.size(); i++) 
            ps[i + 1] = ps[i] + powers[i];

        vector<int> ans;

        for (auto& q: queries) {
            int left = q[0], right = q[1] + 1;
            long long diff = ps[right] - ps[left];

            long long val = 1;
            long long base = 2;
            
            while (diff > 0) {
                if (diff & 1) val = (val * base) % MOD;
                base = (base * base) % MOD;
                diff >>= 1;
            }
            ans.push_back((int)val);
        }
        
        return ans;
    }
};
