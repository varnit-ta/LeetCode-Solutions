class Solution {
public:
    bool check(vector<int>& ct, vector<int>& rc, long long budget, int mid) {
        int n = ct.size();
        int count = 0, left = 0;

        long long tc = 0;
        multiset<int> ms{0};

        for (int right = 0; right < n; right++) {
            tc += rc[right];
            ms.insert(ct[right]);

            while (*ms.rbegin() + (long long)(ms.size() - 1) * tc > budget) {
                ms.erase(ms.find(ct[left]));
                tc -= rc[left];
                left++;
            }

            if (ms.size() - 1 >= mid) return true;
        }

        return false;
    };


    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();

        int left = 0, right = n;

        for (int i = 0; i < n; i++)
            left = min(left, chargeTimes[i] + runningCosts[i]);

        int ans = right;

        while (left <= right) {
            int mid = (left + right)/2;

            if (check(chargeTimes, runningCosts, budget, mid)) {
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return ans;
    }
};