class Solution {
public:
    long long reverse(long long v) {
        long long temp = 0;

        while (v > 0) {
            temp = temp * 10 + v % 10;
            v /= 10;
        }

        return temp;
    }

    bool isPalindrome(long long v) { 
        return v == reverse(v); 
    }

    int superpalindromesInRange(string left, string right) {
        long long L = stol(left), R = stol(right);

        int MAGIC = 100000, total = 0;

        for (int i = 1; i <= MAGIC; i++) {
            string s = to_string(i);

            for (int i = s.size() - 1; i >= 0; i--)
                s += s[i];

            long long v = stol(s);
            v *= v;

            if (v > R)
                break;

            if (v >= L && isPalindrome(v))
                total++;
        }

        for (int i = 1; i <= MAGIC; i++) {
            string s = to_string(i);

            for (int i = s.size() - 2; i >= 0; i--)
                s += s[i];

            unsigned long long v = stol(s);
            v *= v;

            if (v > R)
                break;

            if (v >= L && isPalindrome(v))
                total++;
        }

        return total;
    }
};