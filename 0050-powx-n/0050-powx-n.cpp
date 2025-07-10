/*
    Implements binary exponentiation to compute x^n efficiently.

    - If n is negative, we invert x to handle reciprocal powers (e.g., x^-3 = 1 / x^3).
    - We convert n to a long to avoid overflow when n = INT_MIN.
    
    The core idea is to break down the exponent into powers of 2 using its binary representation.
    Instead of multiplying x by itself n times (O(n)), we reduce it to O(log n) operations.

    For example, to compute x^13:
    - Binary of 13 = 1101
    - This means: x^13 = x^8 * x^4 * x^1
    - We compute powers of x by squaring (x, x^2, x^4, x^8, ...) each step.
    - When a bit is set (like in positions for x^8, x^4, x^1), we multiply it into the result.

    This approach:
    - Only multiplies when needed (if the bit is 1),
    - Squares the base each time (preparing it for higher powers),
    - Shifts the exponent right (divides by 2) each loop iteration.

    This reduces time complexity to O(log n), which is much faster for large n.
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            x = 1/x;

        double pow = 1;
        long num = labs(n);

        while (num){
            if (num & 1){
                pow *= x;
            }

            x *= x;
            num >>= 1;
        }

        return pow;
    }
};