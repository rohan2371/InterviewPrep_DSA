/*
Leetcode link : https://leetcode.com/problems/longest-increasing-subsequence/description/
*/

class Solution {
public:
    int n;
    vector<vector<int>>dp;


    // t.c : o(2^n) , s.c : o(n)
    int rec(vector<int>&nums,int curr_idx,int prev_idx)
    {
        if(curr_idx == n)
            return 0;
        
        int take = 0;
        if(prev_idx == -1 || nums[prev_idx]<nums[curr_idx])
            take = 1+rec(nums,curr_idx+1,curr_idx);
        int not_take = rec(nums,curr_idx+1,prev_idx);
        return max(take,not_take);
            
    }


    // t.c : o(n*n) , s.c : o(n*n) + o(n)(auxilary space -stack)
    /*
    You may think why even i passing prev_idx  instead directly passing 
    curr_element as previous element so that we don't need to maintain 
    2d dp vector but whatever u saying is right but that only works in recursion but not in memoization because we neet to maintain in array whatevery chainging in every step so here u can easily found out that previouse element is chaning whenever we hitting the recursion call so 
    it is comman mistake or some new point i learn today 
    */
    int recMemo(vector<int>&nums,int curr_idx,int prev_idx)
    {
        if(curr_idx==n)
            return 0;
        int take = 0;
        if (prev_idx!=-1 && dp[curr_idx][prev_idx]!=-1)
            return dp[curr_idx][prev_idx];
        if(prev_idx == -1 || nums[prev_idx] < nums[curr_idx])
            take = 1 + recMemo(nums,curr_idx+1,curr_idx);
        int skip = recMemo(nums,curr_idx+1,prev_idx);
        // why this step because we passing previous idx as -1 
        // as he can try write dp[0][-1] that throws runtime error 
        if(prev_idx!=-1)
            return dp[curr_idx][prev_idx] = max(take,skip);
        return  max(take,skip);
    }

      int bottomUp(vector<int>&nums)
    {
        vector<int>vec(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    vec[i] = max(vec[i],vec[j]+1);
            }
        }
        return *max_element(vec.begin(),vec.end());
    }

    
    int lengthOfLIS(vector<int>& nums) {
        n= nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
    //    return rec(nums,0,-1); 
        // return recMemo(nums,0,-1);
    }
};