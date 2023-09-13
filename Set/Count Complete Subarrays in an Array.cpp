/*
    Leetcode Link : https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/
*/




class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for(auto &it : nums)
            st.insert(it);
        
        int cnt = 0;
        
        
        for(int i=0;i<n;i++){
            set<int>temp;
            for(int j=i;j<n;j++){
                temp.insert(nums[j]);
                if(st.size()==temp.size())
                    cnt++;
            }
        }
        return cnt;
    }
};