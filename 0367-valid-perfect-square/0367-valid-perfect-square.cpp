class Solution {
public:
    bool isPerfectSquare(int num) {
        int root = pow(num, 0.5);
        return (root * root == num);
    }
};