class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto sig = getSignature(n);

        for (int i = 1; i <= 1e9; i <<= 1) {
            if (sig == getSignature(i)) 
                return true;
        }
        
        return false;
    }

private:
    array<int, 10> getSignature(int x) {
        array<int, 10> freq = {0};
        while (x > 0) {
            freq[x % 10]++;
            x /= 10;
        }
        return freq;
    }
};
