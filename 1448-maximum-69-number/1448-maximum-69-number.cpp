class Solution {
public:
    int maximum69Number(int num) {
        vector<int> arr;

        while (num > 0) {
            arr.push_back(num % 10);
            num /= 10;
        }

        int i = arr.size() - 1;
        int res = 0;

        while (i >= 0 && arr[i] == 9) {
            res *= 10;
            res += arr[i];
            i--;
        }

        if (i >= 0) {
            res *= 10;
            res += 9;
            i--;
        }

        while (i >= 0) {
            res *= 10;
            res += arr[i];
            i--;
        }

        return res;
    }
};