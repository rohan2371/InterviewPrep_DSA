class Solution {
public:
    vector<int>dp;
    // recursion , t.c : o(2^n) , s.c : o(n)
    int rec(int n)
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        return rec(n-1)+rec(n-2);
    }

    // memoization , t.c : o(n) , s.c : o(n) + o(n)
    int recMemo(int n)
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = recMemo(n-1) + recMemo(n-2);
    }

    // tabluation , t.c : o(n) , s.c : o(n)
    int bottomUp(int n)
    {
        vector<int>vec(n+1);
        vec[0] = 0;
        vec[1] = 1;

        for(int i=2;i<=n;i++)
        {
            vec[i] = vec[i-1] + vec[i-2];
        }
        return vec[n];
    }

    // space optimization 
    int sol4(int n)
    {
        int prev2 = 0;
        int prev = 1;

        for(int i=2;i<=n;i++)
        {
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int fib(int n) {
        dp.resize(n+1,-1);
        // return recMemo(n);
        // return bottomUp(n);
        return sol4(n);
    }
};