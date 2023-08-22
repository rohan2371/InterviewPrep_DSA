/*
    Leetcode link : https://leetcode.com/problems/minimum-falling-path-sum/description/
*/

// accepted 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, 0), cur(m, 0);
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + prev[j];
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) leftDiagonal += prev[j - 1];
                else leftDiagonal += 1e9;
                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) rightDiagonal += prev[j + 1];
                else rightDiagonal += 1e9;
                cur[j] = min(up, min(leftDiagonal, rightDiagonal));
            }
            prev = cur;
        }
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};


// dp -memoization -> gives tle 

class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int rec(vector<vector<int>>&matrix,int row,int col)
    {
        if(col<0 || col>=n)
            return 1e8;
        if(row==0)
            return matrix[row][col];
        
        int dl = matrix[row][col] + rec(matrix,row-1,col-1);
        int dr = matrix[row][col] + rec(matrix,row-1,col+1);
        int st = matrix[row][col] + rec(matrix,row-1,col);
        return min(st,min(dl,dr));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        dp.resize(n,vector<int>(n,-1));
        int res = INT_MAX;
        for(int j=0;j<n;j++)
        {
            int ans = rec(matrix,n-1,j);
            res =  min(res,ans);
        }
        return res;
    }
};