/*
Leetcode Link : https://leetcode.com/problems/separate-black-and-white-balls/description/
*/

// s.c : O(n) and s.c : O(n)
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        vector<int>zero_cnt(n,0);

        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
                zero_cnt[i] = i == n-1 ? 1:zero_cnt[i+1] + 1;
            else
                zero_cnt[i] = i == n-1 ? 0 : zero_cnt[i+1];
        }

        long long ans = 0;

        for(int i=0;i<n;i++){

            if(s[i]=='1'){
                ans+=zero_cnt[i];
            }
        }

        return ans;
    }
};