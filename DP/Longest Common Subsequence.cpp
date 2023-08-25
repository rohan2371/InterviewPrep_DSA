/*
Leetcode link : https://leetcode.com/problems/longest-common-subsequence/description/
*/


class Solution {
public:
    vector<vector<int>>dp;
    int rec(string text1,string text2,int n,int m)
    {
       if(n==0|| m==0)
            return 0;
        if(text1[n-1]==text2[m-1])
            return 1+rec(text1,text2,n-1,m-1);
        else
            return max(rec(text1,text2,n-1,m),rec(text1,text2,n,m-1));
        
        
    }
     


    int recMemo(string text1,string text2,int n,int m)
     {
         if(n==0 || m==0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(text1[n-1]==text2[m-1])
            return dp[n][m] = 1+recMemo(text1,text2,n-1,m-1);
        else
            return dp[n][m] = max(recMemo(text1,text2,n-1,m),
            recMemo(text1,text2,n,m-1));
     }



     int bottomUp(string text1,string text2,int n,int m)
     {
         vector<vector<int>>vec(n+1,vector<int>(m+1,-1));

         for(int i=0;i<=n;i++)
         {
             for(int j=0;j<=m;j++)
             {
                if(i==0 || j==0)
                    vec[i][j] = 0;
                else if(text1[i-1]==text2[j-1])
                    vec[i][j] = 1+vec[i-1][j-1];
                else
                    vec[i][j] = max(vec[i-1][j],vec[i][j-1]);

             }
         }
         return vec[n][m];
     }
     
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m = text2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        // return rec(text1,text2,n,m);
        // return recMemo(text1,text2,n,m);
        return bottomUp(text1,text2,n,m);
    }
};