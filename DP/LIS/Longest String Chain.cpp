/*
Leetcode Link : https://leetcode.com/problems/longest-string-chain/description/
*/




class Solution {
public:
    int n ;
    vector<vector<int>>dp;
    static bool cmp(string &a,string &b)
    {
        return a.size()<b.size();
    }
    bool isSubsequence(string x,string y)
    {
        int n = x.size();
        int m = y.size();

        int i=0,j=0;
        if(m-n==1)
        {
            while(j<m)
            {
                if(x[i]==y[j])
                {
                    i++;
                    if(i==n)
                        return true;
                }
                j++;
            }
        }
        return false;
    }

    int rec(vector<string>&words,int prev_idx,int curr_idx)
    {
        if(curr_idx==n)
            return 0;
        
        int take = 0;
        if(prev_idx==-1 || ((words[prev_idx].length()<words[curr_idx].length()) && isSubsequence(words[prev_idx],words[curr_idx])))
            take = 1+ rec(words,curr_idx,curr_idx+1);
        
        int not_take = rec(words,prev_idx,curr_idx+1);
        return max(take,not_take);
    }


    int recMemo(vector<string>&words,int prev_idx,int curr_idx)
    {
        if(curr_idx==n)
            return 0;
        
        if(prev_idx !=-1 && dp[prev_idx][curr_idx]!=-1)
            return dp[prev_idx][curr_idx];
        int take = 0;
        if(prev_idx==-1 || ((words[prev_idx].size()<words[curr_idx].size()) && isSubsequence(words[prev_idx],words[curr_idx])))
            take = 1+recMemo(words,curr_idx,curr_idx+1);
        int not_take = recMemo(words,prev_idx,curr_idx+1);

        if(prev_idx !=-1)
            dp[prev_idx][curr_idx] = max(take,not_take);
        return max(take,not_take);
    }

    
    int longestStrChain(vector<string>& words) {
        n = words.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        sort(begin(words),end(words),cmp);
       
        return recMemo(words,-1,0);

    }
};