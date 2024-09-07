/*
Leetcode link : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/
*/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n= nums.size();
        int k = 0;
        for(auto it : nums){
            if(it==1)
                k++;
        }
        int one_cnt = 0;
        int min_swap = INT_MAX;


        int i=0,j=0;
        // straightforward check using slding window property
        while(j<n){
            if((j-i +1) <k){
                if(nums[j]==1)
                    one_cnt++;
            }
            else
            {
                if(nums[j]==1)
                    one_cnt++;
                
                min_swap = min(min_swap,k-one_cnt);

                if(nums[i]==1)
                    one_cnt--;
                i++;
            }
            j++;
        }
        // now covering the circular edge case 
        i=n-k+1;
        j=0;
        one_cnt = 0;
        for(int m=i;m<n;m++)
        {
            if(nums[m]==1)
                one_cnt++;
        }
        while(i<n){
            if(nums[j]==1)
                one_cnt++;
            
            min_swap = min(min_swap,k-one_cnt);
            cout<<" i : "<<i<<" j : "<<j<<" one_cnt: "<<one_cnt<<endl;
            if(nums[i]==1)
                one_cnt--;
            i++;
            j++;
        }

        return min_swap;
    }
};