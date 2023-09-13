/*
Leetcode Link : https://leetcode.com/problems/combination-sum-iv/description
*/

class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int rec(int idx,vector<int>&nums,int target)
    {
        if(target==0)
            return 1;
        if(idx>=n  || target<0)
            return 0;

        int take_idx = rec(0,nums,target-nums[idx]);
        int reject_idx = rec(idx+1,nums,target);
        return take_idx + reject_idx; 
    }


    int recMemo(int idx,vector<int>&nums,int target)
    {
        if(target==0)
            return 1;
        if(idx>=n || target<0)
            return 0;
        
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        int take_idx = recMemo(0,nums,target-nums[idx]);
        int reject_idx = recMemo(idx+1,nums,target);

        return dp[idx][target] = take_idx + reject_idx;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        dp.resize(n+1,vector<int>(target+1,-1));
        return recMemo(0,nums,target);
    }
};





// 2nd method here we rejecting the element directly using loop so no need to check reject_idx 
 int recMemo(int idx,vector<int>&nums,int target)
    {
        if(target==0)
            return 1;
        if(idx>=n || target<0)
            return 0;
        
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        // int take_idx = recMemo(0,nums,target-nums[idx]);
        // int reject_idx = recMemo(idx+1,nums,target);

        int result = 0;
        for(int i=idx ;i < n;i++){
            int take_idx = recMemo(0,nums,target-nums[i]);
            result+=take_idx;
        }

        return dp[idx][target] = result;
    }