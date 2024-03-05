#include <cmath>

class Solution {
public:
    bool isInteger(double N){
        double temp2 = N - (int)N;
        if (temp2 > 0) {
            return false;
        }
        return true;
    }

    bool isPowerOfFour(int n) {
        if (n<4 && n != 1){
            return false;
        }else{
            double res = log10(n)/log10(4);
            return isInteger(res);
        }
    }
};