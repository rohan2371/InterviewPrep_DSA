/*
Leetcode Link : https://leetcode.com/problems/is-subsequence/description
*/

// t.c : O(n) , s.c : O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i=0,j=0;
        if(n==0)
            return true;

        int cnt = 0;
        while(j<m)
        {
        
            if(s[i]==t[j])
            {
                i++;
                if(i==n)
                    return true;
                cnt++;
                
            }
            j++;
        }
      
        return false;
    }
};