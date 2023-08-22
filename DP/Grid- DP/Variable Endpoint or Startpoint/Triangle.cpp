/*

    Leetcode Link : https://leetcode.com/problems/triangle/description/
*/
// this problem have fixed starting point but variable ending point 
// the row will be last one that fixed but which column it is not fixed 
// that's why this problem variable grid problem 
class Solution {
public:
    int n;
    vector<vector<int>>dp;

    int rec(vector<vector<int>>&triangle,int row,int col)
    {
        if(row == n-1)
            return triangle[row][col];
        int cost = triangle[row][col] + rec(triangle,row+1,col);
        int diagonal_cost = triangle[row][col] + rec(triangle,row+1,col+1);
        return min(cost, diagonal_cost);
    }

    
    int recMemo(vector<vector<int>>&triangle,int row,int col)
    {
        if(row==n-1)
            return triangle[row][col];
        
        if(dp[row][col] !=-1)
            return dp[row][col];
        int cost = triangle[row][col] + rec(triangle,row+1,col);
        int cost_diagonal =triangle[row][col] +  rec(triangle,row+1,col+1);
        return dp[row][col] = min(cost,cost_diagonal);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        dp.resize(n,vector<int>(n,-1));
        return rec(triangle,0,0);// fixed starting point 
    }
};