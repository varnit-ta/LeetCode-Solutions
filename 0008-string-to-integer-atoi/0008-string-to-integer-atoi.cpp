class Solution {
public:
    bool isNum(char a){
        if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9'){
            return true;
        }
        return false;
    }

    int myAtoi(string s) {
        double result = 0;
        bool isNeg = false;
        bool hasSign = false;
        int placeValue = 1;
        bool hasBegin = false;

        for (int i = 0; i < s.length(); i++){
            char element = s[i];

            if (hasBegin && !isNum(element)){
                break;
            }else if (isNum(element)){
                int num = element - '0';
                result = result * 10;
                result = result + num;
                hasBegin = true;
            }else if (!hasBegin && (element == '+' || element == '-') && !hasSign && isNum(s[i+1])){
                if (element == '-'){
                    isNeg = true;
                    hasBegin = true;
                }
                hasSign = true;
            }else if (result == 0 && element != ' '){
                if (!isNum(element)){
                    return 0;
                }
            }
        }

        if (isNeg){
            result = 0 - result;
        }

        if (result < pow(-2, 31)){
            return pow(-2, 31);
        }else if (result > (pow(2, 31) - 1)){
            return pow(2, 31)-1;
        }

        return result;
    }
};