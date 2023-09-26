/*
Leetcode Link : https://leetcode.com/problems/find-the-difference/description/
*/
// using bit manipulation xor
class Solution {
public:
    char findTheDifference(string s, string t) {
       
        char res = t[0];
        for(int i=0;i<s.size();i++)
        {
           res^=s[i]^t[i+1];
        }
        return res;
    }
};

// using the sort
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(begin(s),end(s));
        sort(begin(t),end(t));

        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i])
                return t[i];
        }
        return t[t.size()-1];
    }
};