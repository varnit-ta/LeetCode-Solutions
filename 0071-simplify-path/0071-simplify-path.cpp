class Solution {
public:
    static string simplifyPath(string path) {
        if (path.back() != '/') path += '/';

        int n = path.size();
        stack<string> stk;

        int i = 0;
        string str;

        while (i < n){
            if (path[i] == '/'){
                if (str == "..") { if (!stk.empty()) stk.pop(); }
                else if (str == ".") str.clear();
                else if (!str.empty()) stk.push(str);
                str.clear();
            }else{
                str += path[i];
            }
            i++;
        }

        string res;
        while (!stk.empty()){
            res = '/' + stk.top() + res;
            stk.pop();
        }

        return (res.empty() ? "/" : res);
    }
};