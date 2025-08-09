class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0)
            return false;

        bool found = false;

        while (n != 0){
            if (found)
                return false;

            if (n & 1)
                found = true;

            n = n >> 1;
        }  

        return true;
    }
};