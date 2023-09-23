/*
Leetcode Link : https://leetcode.com/problems/number-of-matching-subsequences/description/
*/

// brtue force solution 
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int cnt = 0;
        for(int i=0;i<words.size();i++)
        {
            string t = words[i];
            int j=0;
            for(int k=0;k<s.size();k++)
            {
                if(s[k]==t[j])
                {
                    j++;
                }
            }
            if(j==t.size())
            {
                cnt++;
            }
        }
        return cnt;
    }
};