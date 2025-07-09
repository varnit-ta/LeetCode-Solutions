class Solution {
public:
    int hammingWeight(int n) {
        int total = 0;

        while (n >= 1){
            if (n & 1)
                total++;

            n = n >> 1;
        }  

        return total;
    }
};