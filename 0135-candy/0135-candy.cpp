class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i = 1, total = 1;
        int peak = 1, down = 1;

        while (i < n){
            if (ratings[i] == ratings[i - 1]){
                total += 1;
                i++;
                continue;
            }

            peak = 1;

            while (i < n && ratings[i] > ratings[i - 1]){
                peak++;
                total += peak;
                i++;
            }

            down = 1;

            while (i < n && ratings[i] < ratings[i - 1]){
                total += down;
                down++;
                i++;
            }

            if (down > peak){
                total += (down - peak);
            }
        }

        return total;
    }
};