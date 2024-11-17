/*
Leetcode Link : https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/
*/

// t.c : O(n) , s.c : O(1)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1)
            return nums;

        vector<int>result(n-k+1,-1);
        // processing consecutive elements
        int cnt = 1;
        for(int i=1;i<k;i++){
            if(nums[i-1]+1 == nums[i])
                cnt++;
            else
                cnt = 1;
        }

        if(cnt == k)
            result[0] = nums[k-1];

        int i=1,j=k;

        while(j<n){
            if(nums[j] == nums[j-1]+1)
                cnt++;
            else
                cnt = 1;
            if(cnt>=k)
                result[i] = nums[j];
            j++;
            i++;
        }


        return result;
        
        
    }
};