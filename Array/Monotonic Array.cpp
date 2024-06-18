/*

Leetcode Link : https://leetcode.com/problems/monotonic-array/description/

*/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag_inc = true;
        bool flag_dec = true;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<=nums[i+1])
                continue;
            else
                {
                    flag_inc = false;
                    break;
                }

        }

         for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>=nums[i+1])
                continue;
            else
                {
                    flag_dec = false;
                    break;
                }

        }


        if(flag_dec || flag_inc)
            return true;
        
        return false;

    }
};