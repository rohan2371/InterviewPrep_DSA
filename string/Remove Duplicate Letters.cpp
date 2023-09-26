/*
Leetcode Link  : https://leetcode.com/problems/remove-duplicate-letters/description/
*/

// t.c : O(n) , s.c : O(26)~O(1)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool>taken(26,false);
        vector<int>last_index(26,0);

        for(int i=0;i<s.length();i++)
        {
            last_index[s[i]-'a'] = i;
        }

        string res;

        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            int idx = ch-'a';

            if(taken[ch-'a']==true)
                continue;
            while(res.length()>0 && res.back()>ch && last_index[res.back()-'a']>i)
            {
                taken[res.back()-'a'] = false;
                res.pop_back();
            }
            res.push_back(ch);
            taken[ch-'a'] = true;
        }
        return res;
    }
};