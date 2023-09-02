/*
Leetcode Link : https://leetcode.com/problems/extra-characters-in-a-string/description

*/


class Solution {
public:
    int dp[51];
    unordered_map<string,int>mp;
    int n;

    int rec(string &s,int idx){
        if(idx==n)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        string curr = "";
        int minExtra = n;
        for(int i=idx;i<n;i++){
            curr.push_back(s[i]);
            int currExtra = (mp.find(curr)==mp.end())?curr.length():0;
            int nextExtra = rec(s,i+1);
            int totalExtra = currExtra + nextExtra;
            minExtra = min(minExtra,totalExtra);
        }
        return dp[idx] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        for(auto &it : dictionary){
            mp[it]++;
        }
        memset(dp,-1,sizeof(dp));
        return rec(s,0);

    }
};