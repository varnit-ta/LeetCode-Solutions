class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day){
        int count = 0, bloomD = 0;

        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] <= day){
                count++;
            }else{
                bloomD += count/k;
                count = 0;
            }
        }

        bloomD += count/k;

        if (bloomD >= m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((1LL * m * k) > bloomDay.size()) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        int n = bloomDay.size();

        for (int i = 0; i < n; i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int left = mini, right = maxi;
        int res = -1;

        while (left <= right){
            int mid = (left + right)/2;

            if (possible(bloomDay, m, k, mid)){
                res = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return res;
    }
};