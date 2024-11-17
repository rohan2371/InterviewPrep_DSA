/*
Leetcode Link : https://leetcode.com/problems/extra-characters-in-a-string/description

*/

// top down insted of using set here we using map 
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


// top down dp 
// t.c : 0(n*n*n) and s.c : o(number substring in dictionary)

class Solution {
public:
    int dp[51];
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string>st(begin(dict),end(dict));
        
        memset(dp,-1,sizeof(dp));
        return solve(0,s,st,n);
    }

    int solve(int i,string s,unordered_set<string>&st,int  n)
    {
        if(i>=n)
            return 0;

        if(dp[i]!=-1)
            return dp[i];
        int result = 1+solve(i+1,s,st,n);

        for(int j=i;j<n;j++){
            string curr = s.substr(i,j-i+1);
            if(st.find(curr) != st.end()){
                result = min(result,solve(j+1,s,st,n));
            }
        }

        return dp[i] = result;
    }
};