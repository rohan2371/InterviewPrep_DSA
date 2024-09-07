/*
Leetcode link : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/
*/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>subarr;
        const int mod = 1e9+7;
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                subarr.push_back(sum);
            }
        }

        sort(subarr.begin(),subarr.end());
        int ans = 0;
        for(int i=left-1;i<right;i++)
        {
            ans =  (ans+subarr[i])%mod;
        }
        return ans;
    }
};
