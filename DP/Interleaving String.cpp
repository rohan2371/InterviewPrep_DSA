/*
Leetcode Link : https://leetcode.com/problems/interleaving-string/
*/

// 3-dp
class Solution {
public:
    int n,m,z;
    int dp[101][101][201];
    bool rec(string s1,string s2,string s3,int i,int j,int k)
    {
        if(i==n && j==m && k==z)
            return true;
        if(k>=z)
            return false;
    
        bool res = false;
        if(s1[i]==s3[k])
            res |= rec(s1,s2,s3,i+1,j,k+1);
        if(s2[j]==s3[k])
            res|= rec(s1,s2,s3,i,j+1,k+1);
        return  res;
    }

    // t.c : o(n*m*z) , sp:o(n) * o(n*m*z) // accepted
     bool recMemo(string s1,string s2,string s3,int i,int j,int k)
    {
        if(i==n && j==m && k==z)
            return true;
        if(k>=z)
            return false;
        
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        bool res = false;
        if(s1[i]==s3[k])
            res |= recMemo(s1,s2,s3,i+1,j,k+1);
        if(s2[j]==s3[k])
            res|= recMemo(s1,s2,s3,i,j+1,k+1);
        return dp[i][j][k] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.length();
        m=s2.length();
        z=s3.length();
        if(n+m > z)
            return false;
        if(n+m < z)
            return false;
        memset(dp,-1,sizeof(dp));
        return recMemo(s1,s2,s3,0,0,0);
    }
};

// 2-d 


class Solution {
public:
    int m, n, N;
    int t[101][101]; //{-1, 0, 1}
    //O(m*n)
    bool solve(int i, int j, string& s1, string& s2, string& s3) {
        
        if(i == m && j == n && i+j == N) {
            return true;
        }
        
        if(i+j >= N) //other string didn't get consumed at all
            return false;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        bool result = false;
        
        if(i < m && s1[i] == s3[i+j]) {
            result = solve(i+1, j, s1, s2, s3);
        }
        
        if(result == true)
            return t[i][j] = result;
        
        if(j < n && s2[j] == s3[i+j]) {
            result = solve(i, j+1, s1, s2, s3);
        }
        return t[i][j] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
          m = s1.length();
        n = s2.length();
        N = s3.length();
        memset(t, -1, sizeof(t));
        return solve(0, 0, s1, s2, s3);
    }
};