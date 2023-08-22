/*
Problem link : https://leetcode.com/problems/climbing-stairs/description/
*/

class Solution {
public:
    vector<int>dp;

    // recursion t.c : o(2^n) ,s.c : o(n)
    int rec(int n)
    {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        int step1 = rec(n-1);
        int step2 = rec(n-2);
        return step1+step2;
    }

    // memoization t.c : o(n) , s.c : o(n)+o(n)
    int recMemo(int n)
    {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int step1 = recMemo(n-1);
        int step2 = recMemo(n-2);
        return dp[n] = step1+step2;
    }

    // bottom up 
    int tabluation(int n)
    {
        vector<int>vec(n+1,-1);
        vec[i]
        for(int i=0;i<=n;i++)
        {
            if(i==0)
                vec[i] = 1;
            else 
            {
                int step2 = 0;
                int step1 = vec[i-1];
                if(i>1)
                    step2 = vec[i-2];
                
                vec[i] = step1 + step2;
            }
        }
        return vec[n];
    }

    int climbStairs(int n) {
        dp.resize(n+1,-1);
        // return rec(n);
        return tabluation(n);
   
    }
};