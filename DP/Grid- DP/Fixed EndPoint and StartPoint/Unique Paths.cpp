
/*
Leetcode link : https://leetcode.com/problems/unique-paths/
*/

/*
62. Unique Paths
Medium

There is a robot on an m x n grid. The robot is initially located at
the top-left corner (i.e., grid[0][0]). The robot tries to move to
the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or
right at any point in time.

Given the two integers m and n, return the number of possible unique paths that
the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Input: m = 3, n = 7
Output: 28

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/
public class UniquePathOne {
    static int rec(int m,int n)
    {
        if(m==0 && n==0)
            return 1;
        if(m<0 || n<0)
            return 0;
        int up = rec(m-1,n);
        int left= rec(m,n-1);
        return up+left;
    }

    // memoization because of overlapping subproblem
    static int recMemo(int row,int col,int dp[][])
    {
        if(row==0 && col==0)
            return 1;
        if(row<0 || col<0)
            return 0;

        if(dp[row][col]!=-1)
            return dp[row][col];

        return dp[row][col] = recMemo(row-1,col,dp) + recMemo(row,col-1,dp);
    }

    // bottom up approach
    static int bottomUp(int row,int col)
    {
        int dp[][] = new int[row][col];
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 && j==0)
                     dp[i][j] = 1;
                else
                {
                    int up =0,left=0;
                    if(i-1>=0)
                        up = dp[i-1][j];
                    if(j-1>=0)
                        left = dp[i][j-1];
                    dp[i][j] = up+left;
                }

            }
        }
        return dp[row-1][col-1];
    }
    public static void main(String[] args) {
        int m=3,n=7;
        int ans = rec(m-1,n-1);
        System.out.println(ans);

        int dp[][] = new int[m][n];
        for(int row[] :dp)
        {
            Arrays.fill(row,-1);
        }
        int ans2 = recMemo(m-1,n-1,dp);
        System.out.println("recMemo : "+ans2);
        System.out.println("bottom up : "+bottomUp(m,n));

    }
}
