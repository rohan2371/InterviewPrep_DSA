

/*
63. Unique Paths II
Medium

You are given an m x n integer array grid. There is a robot initially located at the top-left corner
 (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
 The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

 */
public class UniquePathTwo {

    static int rec(int row,int col,int grid[][])
    {
        if(row==0 && col==0)
            return 1;
        if(row<0 || col<0)
            return 0;
        if(grid[row][col]==1)
            return 0;

        int up = rec(row-1,col,grid);
        int left = rec(row,col-1,grid);
        return up+left;

    }

    // got tle
    int memoRec(int row,int col,int grid[][],int dp[][])
    {
        if(row>=0 && col>=0 && grid[row][col] == 1)
            return 0;
        if(row==0 && col==0 && grid[row][col] !=1)
            return 1;
        if(row<0 || col<0)
            return 0;

        int up = rec(row-1,col,grid);
        int left = rec(row,col-1,grid);

        return dp[row][col] =  up+left;
    }

    private int tabularMethod(int grid[][])
    {
        int n=grid.length;
        int m= grid[0].length;
        int dp[][] = new int[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    dp[i][j] = 0;
                else if(i==0 && j==0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0,left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = up+left;
                }
            }
        }

        return dp[n-1][m-1];
    }

    public static void main(String[] args) {
        int grid[][] = {{0,0,0},{0,1,0},{0,0,0}};
        int row = grid.length;
        int col = grid[0].length;

        int ans = rec(row-1,col-1,grid);
        System.out.println("rec : "+ans);

    }
}
