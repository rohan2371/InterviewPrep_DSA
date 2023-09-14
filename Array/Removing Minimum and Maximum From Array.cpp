/*
Leetcode Link : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description
*/


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_element = INT_MAX , max_element = INT_MIN;
        int min_idx = 0, max_idx = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(min_element > nums[i])
            {
                min_element = nums[i];
                min_idx = i;
            }
            if(max_element < nums[i])
            {
                max_element = nums[i];
                max_idx = i;
            }
        }

        // complete left to right  removel of both element 
        int completeLeftRemovel = 0;
        if(min_idx < max_idx)
        {
            completeLeftRemovel=max_idx+1;
        }
        else
        {
            completeLeftRemovel = min_idx+1;
        }
        // complete removel right to left both elements 
        int completeRightRemovel = 0;
        if(min_idx<max_idx)
        {
            completeRightRemovel = n-min_idx;
        }
        else
        {
            completeRightRemovel = n-max_idx;
        }

        // removing one element from left and one element from right 
        int leftRemovel = 0,rightRemovel = 0;
        if(min_idx < max_idx)
        {
            leftRemovel = min_idx + 1;
        }
        else
        {
            leftRemovel = max_idx + 1;
        }

        // removing element from right side 
        if(min_idx > max_idx)
        {
            rightRemovel = n-min_idx;
        }
        else
        {
            rightRemovel = n -max_idx;
        }

        int res = min(completeLeftRemovel,completeRightRemovel);

        return min(res,leftRemovel + rightRemovel);
        

    }
};