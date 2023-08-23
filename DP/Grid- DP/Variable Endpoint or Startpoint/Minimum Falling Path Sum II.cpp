/*
    Leetcode link : https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

*/
/*
[-73,61,43,-48,-36], -> -73 
[3,30,27,57,10], -> 10
[96,-76,84,59,-15], -> -76
[5,-49,76,31,-7], -> -7
[97,91,61,-46,67]] -> -46

for example if i take -73 as first element for the next path i need to traverse entire second row 
except the same column that is 0th column and need to return minimum of it 

op : -192 


*/
// solved by rohan konkatti hardest problem on leetcode on dp 
// t.c : o(n)*o(m) , s.c : o(n) + o(m)
class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int rec(vector<vector<int>>&grid,int row,int col)
    {
        // if(col<0 || col>=n)
        //     return 1e8;
        if(row==0)
            return grid[row][col];
        int ans = 1e8,temp = 1e8;
        if(dp[row][col] !=-1)
            return dp[row][col];
        for(int j=0;j<n;j++)
        {
            
            if(j!=col)
                 temp = grid[row][col] + rec(grid,row-1,j);
            ans = min(ans,temp);
        }
        return dp[row][col] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n,vector<int>(n,-1));
        if(n==1)    
            return grid[0][0];
        // dp.resize(n,vector<int>(n,-1));
        int res = INT_MAX;
        for(int j=0;j<n;j++)
        {
            int ans = rec(grid,n-1,j);
            res = min(res,ans);
        }
        return res;
    }
};