/*
leetcode Link : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>deq; // stores index in monotonic increasing order of cumulativeSum
        vector<long long>cumlativesum(n,0);

        int ans = INT_MAX ;
        int j = 0;
        while(j < n )
        {
            if(j== 0)
                cumlativesum[j] = nums[j];
            else
                cumlativesum[j] = cumlativesum[j-1]+nums[j];
        

            if(cumlativesum[j]>=k)
                ans = min(ans,j+1);
            
            // need to shrink the window or  not 
            while(!deq.empty() && cumlativesum[j] - cumlativesum[deq.front()] >= k)
            {
                ans = min(ans,j-deq.front());
                deq.pop_front();
            }

            while(!deq.empty() && cumlativesum[j]<cumlativesum[deq.back()])
            {
                deq.pop_back();
            }
            deq.push_back(j);
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};