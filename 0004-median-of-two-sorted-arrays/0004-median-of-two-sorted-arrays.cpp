class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        vector<double> v(num1.size() + num2.size());
        vector<double>:: iterator it, st;

        merge(num1.begin(), num1.end(), num2.begin(), num2.end(), v.begin());

        int len = v.size();
        sort(v.begin(), v.end());

        if (len%2 != 0){
            return v.at((len-1)/2);
        }else{
            double n1 = v.at(len/2);
            double n2 = v.at((len-2)/2);

            
            return ((n1+n2)/2);
        }
    }
};