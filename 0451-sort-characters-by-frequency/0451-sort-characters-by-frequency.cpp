class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(char i:s){
            mp[i]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto& p : mp) {
           pq.push({p.second, p.first});
        }
        string ans="";
        while(!pq.empty()){
            auto [x,y]=pq.top();
            pq.pop();
            ans+=string(x,y);
        }
        return ans;
    }
};