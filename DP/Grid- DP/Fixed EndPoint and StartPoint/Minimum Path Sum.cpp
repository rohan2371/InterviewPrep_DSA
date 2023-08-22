/*
    Leetcode Link : https://leetcode.com/problems/minimum-path-sum/description/
*/


class Solution {
    int rec(int row,int col,int grid[][])
    {
        if(row==0 && col==0)
            return grid[0][0];
        if(row<0 || col<0)
            return Integer.MAX_VALUE-200;
        
        // why i am subtracting 200 because max_int + grid[row][col]
        // our interger overflow up or down become negative 
        // last return min value so that be our ans

        int up = grid[row][col]+rec(row-1,col,grid);
        int left = grid[row][col]+rec(row,col-1,grid);

        return Math.min(up,left);
    }

    int recMemo(int row,int col,int grid[][],int dp[][])
    {
        if(row==0 && col==0)
            return grid[0][0];
        if(row<0 || col<0)
            return (int)Math.pow(10,9);
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        int up = grid[row][col]+recMemo(row-1,col,grid,dp);
        int left = grid[row][col]+recMemo(row,col-1,grid,dp);

        return dp[row][col] = Math.min(up,left);
    }

    int bottomUp(int row,int col,int grid[][])
    {
        int dp[][] = new int[row][col];

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = grid[i][j];
                else{
                    int up=grid[i][j],left=grid[i][j];
                    if(i>0)
                        up += dp[i-1][j];
                    else
                        up+=(int)Math.pow(10,9);
                    if(j>0)
                        left +=dp[i][j-1]; 
                    else
                        left+=(int)Math.pow(10,9);

                    dp[i][j] = Math.min(up,left);
                }
            }
        }
        return dp[row-1][col-1];

    }
    
    public int minPathSum(int[][] grid) {
        int row= grid.length;
        int col = grid[0].length;
        // return rec(row-1,col-1,grid);
        int dp[][] = new int[row][col];
        for(int arr[] :dp)
        {
            Arrays.fill(arr,-1);
        }
        return recMemo(row-1,col-1,grid,dp);
        // return bottomUp(row-1,col-1,grid);
    }
}