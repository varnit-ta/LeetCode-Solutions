class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = INT_MAX;

        function<long long(const vector<int>&, int)> hoursRequired = [&](const vector<int>& piles, int speed) -> long long {
            long long hours = 0;
            for (int i = 0; i < piles.size(); i++) hours += (piles[i] + speed - 1)/speed;
            return hours;
        };

        function<void(int, int)> findMin = [&](int left, int right) -> void {
            if (left <= right){
                int mid = (left + right)/2;
                long long timeTaken = hoursRequired(piles, mid);

                if (timeTaken <= h){
                    minSpeed = mid;
                    findMin(left, mid - 1);
                }else{
                    findMin(mid + 1, right);
                }
            }
        };

        findMin(1, *max_element(piles.begin(), piles.end()));
        return minSpeed;
    }
};