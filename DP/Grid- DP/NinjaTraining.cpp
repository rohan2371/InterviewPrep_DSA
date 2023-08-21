/*
problem link : https://www.codingninjas.com/studio/problems/ninja-s-training_3621003

*/




import java.util.Arrays;

public class NinjaTraining {
    private static int fun(int day, int last, int points[][]) {
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {

                if (task != last) {
                    maxi = Math.max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int ans = points[day][task] + fun(day - 1, task, points);
                maxi = Math.max(ans, maxi);
            }
        }
        return maxi;
    }


    private static int funMem(int day, int last, int points[][], int dp[][]) {
        if(dp[day][last] !=-1)
            return dp[day][last];

        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task <=2; task++) {

                if (task != last) {
                    maxi = Math.max(maxi, points[0][task]);
                }
            }
            return dp[day][last] = maxi;
        }



        int maxi = 0;
        for (int task = 0; task <=2; task++) {
            if (task != last) {
                int activity = points[day][task] + funMem(day - 1, task, points,dp);
                maxi = Math.max(activity, maxi);
            }
        }
        return dp[day][last] = maxi;
    }

    public static void main(String[] args) {
        int n = 3;
        int arr[][] = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
        int last = 3;
        int day = n;

        int ans = fun(n - 1, last, arr);
        System.out.println("ans : " + ans);

        // memoization because above problem have overlapping subproblem

        int dp[][] = new int[n][4];
        for(int[] row : dp){
            Arrays.fill(row,-1);
        }
        int ans2 = funMem(day-1,last,arr,dp);
        System.out.println("ans2 : "+ans2);
    }
}
