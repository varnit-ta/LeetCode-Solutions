class Solution {
public:
    int daysReq(int mx, vector<int>& weights){
        int day = 1, load = 0;

        for (int i = 0; i < weights.size(); i++){
            if (load + weights[i] > mx){
                day++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }

        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left <= right){
            int mid = (left + right)/2;

            if (daysReq(mid, weights) > days){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left;
    }
};