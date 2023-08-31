/*
Leetcode Link : https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

*/

class Solution {
public:
    int n;
    // time complxity :O(n*n) , space complexity : O(n)(auxilary space)
    int rec(vector<int>&nums,int curr_idx,int prev_idx)
    {
        if(n == curr_idx)
            return 0;
        int take = 0;
        if(prev_idx ==-1 || nums[prev_idx] < nums[curr_idx])
            take  = 1+rec(nums,curr_idx+1,curr_idx);
        return take;
        
    }

    // you can convert below code into for loop  
    // t.c : O(n) , s.c :O(1)
    int slidingWindow(vector<int>&nums)
    {
        int i=0,j=1;
        int maxi = 1;
        int curr_count = 1;
        while(j<n)
        {

            if(nums[i]<nums[j])
            {
                curr_count++;
                maxi = max(maxi,curr_count);
               
            }
            else if(nums[i] == nums[j])
            {
                
                curr_count = 1;
            }
            else
            {
                maxi = max(maxi,curr_count);
                curr_count = 1;
            }
            i++;
            j++;
        }
        return maxi;
    }
    int findLengthOfLCIS(vector<int>& nums) {
        n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int ans = rec(nums,i,-1);
            maxi = max(maxi,ans);
        }   
         return maxi;
    }
};

Longest Continuous Increasing Subsequence 