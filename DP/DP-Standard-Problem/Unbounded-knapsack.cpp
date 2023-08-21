package dynamic_programming;

public class CUnboundedKnapsack {
    // unbounded knapsack memoization
    private static int ubkMemoization(int wt[], int val[], int W, int N, int dp[][]) {
        if (N == 0 || W == 0)
            return 0;
        if (dp[N][W] != -1)
            return dp[N][W];
        if (wt[N - 1] <= W) {
            return dp[N][W] = Math.max(val[N - 1] + ubkMemoization(wt, val, W - wt[N - 1], N, dp),
                    ubkMemoization(wt, val, W, N - 1, dp));
        } else {
            return dp[N][W] = ubkMemoization(wt, val, W, N - 1, dp);
        }
    }

    private static int unboundedKnapsack(int wt[], int val[], int W, int N) {
        if (N == 0 || W == 0)
            return 0;
        if (wt[N - 1] > W) {
            return unboundedKnapsack(wt, val, W, N - 1);
        } else {
            return Math.max(val[N - 1] + unboundedKnapsack(wt, val, W - wt[N - 1], N)
                    , unboundedKnapsack(wt, val, W, N - 1));
        }
    }


    public static void main(String[] args) {
        int wt[] = {10, 20, 30};
        int val[] = {60, 100, 120};
        int N = val.length;
        int W = 50;

        int dp[][] = new int[N + 1][W + 1];
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= W; j++) {
                dp[i][j] = -1;
            }
        }
        int ans = unboundedKnapsack(wt, val, W, N);
        System.out.println("using recursion : " + ans);
        System.out.println("using memoization : " + ubkMemoization(wt, val, W, N, dp));

    }
}
