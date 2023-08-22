/*
    Leetcode link : https://leetcode.com/problems/house-robber/description/

*/


class Solution {
public:
    vector<int>dp;

    // recursion code
    // t.c : o(2^n), s.c : o(n)
     int rec(vector<int>&nums,int i)
    {
        if(i==0)
            return nums[0];
        if(i<0)
            return 0;
        int pic = nums[i] + rec(nums,i-2);
        int notpic = rec(nums,i-1);
        return  max(pic,notpic);
    }
    // dp memoization code
    // t.c : o(n) , s.c : o(n) + o(n)
    int recMemo(vector<int>&nums,int i)
    {
        if(i==0)
            return nums[0];
        if(i<0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int pic = nums[i] + Memo(nums,i-2);
        int notpic = recMemo(nums,i-1);
        return dp[i] = max(pic,notpic);
    }
    
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        // return rec(nums,nums.size()-1);

        //bottom up approach or tabulation 
        // t.c : o(n), s.c : o(n)
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
                dp[i] = nums[i];
            else
            {
                int take = nums[i];
                if(i>1)
                    take +=dp[i-2];

                int not_take = dp[i-1];
                dp[i] = max(take,not_take);
            }
        }
        // return dp[nums.size()-1];

        // t.c : o(n), s.c : o(1)
        int prev = nums[0];
        int prev2 = 0;
        space optimization 
        for(int i=1;i<nums.size();i++)
        {
            int take = nums[i];
            if(i>1)
                take+=prev2;
            
            int not_take = prev;
            int curr = max(not_take,take);
            prev2 = prev;
            prev = curr;

        }
        return prev;
    }
};






 int sol(vector<int>&vec)
    {
        int prev = vec[0];
        int prev1 = 0;
        for(int i=1;i<vec.size();i++)
        {
            int take = vec[i];
            if(i>1)
                take+=prev1;
            int not_take = prev;
            int curr = max(take,not_take);
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int>temp1;// exclude first ele
        vector<int>temp2;// exclude last ele
        int n = nums.size();
        if(n==1)
            return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }

        int ans1 = sol(temp1);
        int ans2 = sol(temp2);
        return max(ans1,ans2);
    }