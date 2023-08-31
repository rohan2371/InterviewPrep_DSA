/*
Leetcode Link : https://leetcode.com/problems/maximum-length-of-pair-chain/description/
*/


class Solution {
public:
    int n ;
    vector<vector<int>>dp;
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[0]<b[0];
    }

     int rec(vector<vector<int>>&pairs,int prev_idx,int curr_idx)
    {
        if(curr_idx == n)
            return 0;
        

        int take = 0;
        if(prev_idx == -1 || pairs[prev_idx][1] < pairs[curr_idx][0])
            take = 1 + rec(pairs,curr_idx,curr_idx+1);
        
        int not_take = rec(pairs,prev_idx,curr_idx+1);
        return max(take,not_take);
        
    }

    int recMemo(vector<vector<int>>&pairs,int prev_idx,int curr_idx)
    {
        if(curr_idx == n)
            return 0;
        
        if(prev_idx !=-1 && dp[prev_idx][curr_idx] !=-1)
            return dp[prev_idx][curr_idx];

        int take = 0;
        if(prev_idx == -1 || pairs[prev_idx][1] < pairs[curr_idx][0])
            take = 1 + recMemo(pairs,curr_idx,curr_idx+1);
        
        int not_take = recMemo(pairs,prev_idx,curr_idx+1);
        if(prev_idx !=-1)
            dp[prev_idx][curr_idx] = max(take,not_take);
        return max(take,not_take);
        
    }

    int bottomUp(vector<vector<int>>&pairs)
    {
        vector<int>res(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1]<pairs[i][0])
                      res[i] = max(res[i],res[j]+1);
            }
        }
        return *max_element(res.begin(),res.end());
    }

    
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        dp.resize(n,vector<int>(n,-1));
        sort(pairs.begin(),pairs.end(),cmp);
        // return rec(pairs,-1,0);
        return recMemo(pairs,-1,0);
    }
};