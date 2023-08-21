package dynamic_programming;

public class AKnapsack {

    private static int knpasackMe(int wt[], int val[], int n, int w, int dp[][]) {
        if (n == 0 || w == 0)
            return 0;

        if (dp[n][w] != -1)
            return dp[n][w];

        if (wt[n - 1] > w) {
            return dp[n][w] = knpasackMe(wt, val, n - 1, w, dp);
        } else {
            return dp[n][w] = Math.max(val[n - 1] + knpasackMe(wt, val, n - 1, w - wt[n - 1], dp),
                    knpasackMe(wt, val, n - 1, w, dp));
        }

    }

    public static int knapSackRecursive(int wt[], int val[], int w, int n) {
        if (n == 0 || w == 0) {
            return 0;
        }
        if (wt[n - 1] <= w) {
            return Math.max(val[n - 1] + knapSackRecursive(wt, val, w - wt[n - 1], n - 1), knapSackRecursive(wt, val, w, n - 1));
        } else {
            return knapSackRecursive(wt, val, w, n - 1);
        }
    }

    public static void main(String[] args) {
        int wt[] = {10, 20, 30};
        int val[] = {60, 100, 120};
        int w = 50;
        // here wt and val both have same weight
        int n = val.length;
        int ans = knapSackRecursive(wt, val, w, n);
        System.out.println("using recursion ans : " + ans);

        int dp[][] = new int[1001][1001];
        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < 1001; j++) {
                dp[i][j] = -1;
            }
        }

        System.out.println("memoization method : " + knpasackMe(wt, val, n, w, dp));
    }
}
