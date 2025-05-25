class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long lsum = 0, rsum = 0;
        int lindex = 0, rindex = cardPoints.size() - 1;

        while (lindex < cardPoints.size() && lindex < k) lsum += cardPoints[lindex++];
        long long total = lsum;
        lindex--;

        while (lindex >= 0){
            lsum -= cardPoints[lindex--];
            rsum += cardPoints[rindex--];

            total = max(total, lsum + rsum);
        }

        return total;
    }
};