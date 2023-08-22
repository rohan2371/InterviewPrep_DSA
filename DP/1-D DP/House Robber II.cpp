/*
Leetcode Link : https://leetcode.com/problems/house-robber-ii/
*/

class Solution {
public:
    int n;
    int rec(vector<int>&vec,int i,vector<int>&dp)
    {
        if(i==0)
            return vec[i];
        if(i<0)
            return 0;
        if(dp[i] !=-1)
            return dp[i];
        
        int take = vec[i] + rec(vec,i-2,dp);
        int not_take = 0+ rec(vec,i-1,dp);
        return dp[i] = max(take,not_take);

    }
    int rob(vector<int>& nums) {
    
        n = nums.size();
        if(n==1)
            return nums[0];
        vector<int>dp1(n-1,-1);
        vector<int>temp1;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                temp1.push_back(nums[i]);
        }
        vector<int>dp2(temp1.size(),-1);
        int ans1 = rec(nums,n-2,dp1);// exclude last element 
        int ans2 = rec(temp1,temp1.size()-1,dp2);// exclude first element

        return max(ans1,ans2);
    }

};