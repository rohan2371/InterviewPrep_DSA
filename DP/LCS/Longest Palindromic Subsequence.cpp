/*
Leetcode link : https://leetcode.com/problems/longest-palindromic-subsequence/description/
*/



class Solution {
public:
    vector<vector<int>>dp;
    string reverseString(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
    }
    // t.c - o(2^n) , s.c : o(n)-> stack space
    
    int lcs(string x,string y,int n,int m)
    {
        if(n==0 || m==0)
            return 0;
        if(x[n-1]==y[m-1])
            return 1+lcs(x,y,n-1,m-1);
        else
            return max(lcs(x,y,n,m-1),lcs(x,y,n-1,m));
    }

    // t.c : o(n*m) , s.c : o(n)+o(n*m);
     int lcsMemo(string x,string y,int n,int m)
    {
        if(n==0 || m==0)
            return 0;
        if(dp[n][m] !=-1)
            return dp[n][m];
        if(x[n-1]==y[m-1])
            return dp[n][m] =  1+lcsMemo(x,y,n-1,m-1);
        else
            return dp[n][m] = max(lcsMemo(x,y,n,m-1),lcs(x,y,n-1,m));
    }
   
   // tabluation
    // t.c : o(n*m) , s.c : o(n*m)
   int lcsTablue(string x,string y,int n,int m)
   {
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=m;j++)
           {
               if(i==0 || j==0)
                    dp[i][j] = 0;
               else if(x[i-1]==y[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
               else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
           }
       }
       return dp[n][m];
   }
    int longestPalindromeSubseq(string s) {
        string revS=reverseString(s);
        int n = s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        // int ans = lcs(s,revS,n,n);
        return lcsTablue(s,revS,n,n);
        
    }
};