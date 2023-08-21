package dynamic_programming;
/*
    0-1 Knapsack problems
    1.subset sum
    2.equal sum partition
    3.count of subset sum
    4.minimum subset sum diff
    5. target sum
    6. count the number of subset with a given difference
*/

public class BKnapsackApplication {
// problem 1 - subset sum
/*
arr[] = {2,3,7,8,10} ,
sum : 11
Q : check the array have any subset whose sum  equal to sum if yes then return true otherwise false

the question is similar to 0-1 knapsack here every element in array we have two options one is include
and another is exclude if value of element is less than sum
else we have only option is remaining is to exclude
 first i write recursion code then memozation(bottom up)  then top-down

 if sum = 0 how many present in array does't matter we always get answer true is reason is
 i not include any elemnts like  {} empty array have sum equal to zero
 and array size zero then our answer will be false
 because whatever sum we cant get our target
 ex : arr= {} , sum = 12
 op : false

*/

    // recursion sol
    private static boolean subsetSumRecursion(int arr[], int sum, int n) {
        if (n == 0)
            return false;
        if (sum == 0)
            return true;

        if (arr[n - 1] <= sum) {
            return subsetSumRecursion(arr, sum - arr[n - 1], n - 1) ||
                    subsetSumRecursion(arr, sum, n - 1);
        } else {
            return subsetSumRecursion(arr, sum, n - 1);
        }

    }

    // bottom up or memoization method
    private static int subsetSumMemoization(int arr[], int sum, int n, int dp[][]) {
        if (n == 0)
            return 0;
        if (sum == 0)
            return 1;

        if (dp[n][sum] != -1)
            return dp[n][sum];
        if (arr[n - 1] <= sum) {
            return dp[n][sum] = subsetSumMemoization(arr, sum - arr[n - 1], n - 1, dp) |
                    subsetSumMemoization(arr, sum, n - 1, dp);
        } else {
            return dp[n][sum] = subsetSumMemoization(arr, sum, n - 1, dp);
        }

    }










    // subset sum partition problem
    /*
 416. Partition Equal Subset Sum -> Medium

Given an integer array nums, return true if you can partition the array
into two subsets such that the sum of the elements in both subsets
 is equal or false otherwise.


Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100


// if sum sum is odd number it is impossible to divided into two same part we return false if number is
odd

     */
    // recursion solution
    private static boolean subsetSum(int nums[],int sum,int n)
    {
        if(n==0)
            return false;
        if(sum==0)
            return true;
        if(nums[n-1]<=sum)
            return subsetSum(nums,sum-nums[n-1],n-1) ||
                    subsetSum(nums,sum,n-1);
        else
            return subsetSum(nums,sum,n-1);
    }
    // memoization method
    private static int subsetSumMem(int nums[],int sum,int n,int dp[][])
    {
        if(n==0)
            return 0;
        if(sum==0)
            return 1;
        if(dp[n][sum] !=-1)
            return dp[n][sum];

        if(nums[n-1]<=sum)
        {
            return dp[n][sum] = subsetSumMem(nums,sum-nums[n-1],n-1,dp) |
                    subsetSumMem(nums,sum,n-1,dp);
        }
        else
        {
            return dp[n][sum] = subsetSumMem(nums,sum,n-1,dp);
        }
    }









// problem 3 : count of subset  of given sum
/*
arr[] = {2,3,5,6,8,10}
sum = 10
op -> 3
explanation : {2,3,5},{10},{2,8}

 */
// recursion sol

    private static int subsetSumCountRec(int arr[],int sum,int n)
    {
        if(n==0)
            return 0;
        if(sum==0)
        {
            return 1;
        }


        int include = 0,exclude = 0;

        if(arr[n-1]<=sum)
            include =  subsetSumCountRec(arr,sum-arr[n-1],n-1) +
                     subsetSumCountRec(arr,sum,n-1);
        else
            exclude = subsetSumCountRec(arr,sum,n-1);
        return include+exclude;

    }



    public static void main(String[] args) {
        // problem 1
        int arr[] = {2, 3, 7, 8, 10};
        int sum = 11;
        int n = arr.length;
        boolean ans = subsetSumRecursion(arr, sum, n);
        System.out.println("subset possible : " + ans);
        int dp[][] = new int[n + 1][sum + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0)
                    dp[i][j] = 0;
                else if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = -1;

            }
        }
        System.out.println("using memoization : " + subsetSumMemoization(arr,sum,n,dp));











        // subset sum partition problem 2
        int nums[] = {1,5,11,5};
        int sizeNums = nums.length;
        int sumNums =0;
        for(int i=0;i<sizeNums;i++)
        {
            sumNums+=nums[i];
        }
        // if sumNums is odd print false -> not possible to divided two equal sum
        if((sumNums&1) == 1)
            System.out.println("not possible to partition  ");

        int target = sumNums/2;
        boolean res1 = subsetSum(nums,sumNums/2,sizeNums);
        if(res1){
            System.out.println("it is possible to divide  ");
        }else{
            System.out.println("not possible to divide");
        }
        int dp2[][] = new int[sizeNums+1][target+1];
        for(int i=0;i<=sizeNums;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(i==0)
                    dp2[i][j] = 0;
                else if(j==0)
                    dp2[i][j] = 1;
                else dp2[i][j] = -1;
            }
        }
        int res2 = subsetSumMem(nums,target,sizeNums,dp2);
        if(res2==1){
            System.out.println("partition is possible");
        }else{
            System.out.println("partition is not possible ");
        }




        // problem 3
        int arr3[] = {2,3,5,6,8,10};
        int n3 = arr3.length;
        int sum3 = 10;
        int cnt = subsetSumCountRec(arr3,sum3,n3);
        System.out.println("subsetSum Count : "+cnt);





    }
}
