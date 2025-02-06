class Solution {
public:
    /*
        string::npos is a special constant value in C++ that represents 
        "no position". It is returned when a search operation, such as 
        find(), fails to find the target substring.
    */
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        return (s + s).find(goal) != string::npos;
    }
};