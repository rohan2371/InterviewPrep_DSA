/*
Leetcode Link : https://leetcode.com/problems/string-compression-iii/description/
*/

// t.c : O(n) and s.c :O(1)
class Solution {
public:
    string compressedString(string word) {
        int n = word.length();

        char prev = word[0];
        int cnt = 1;
        string ans = "";

        for(int i=1;i<n;i++)
        {

            // chk condition in question  
            if(word[i] == word[i-1] && cnt<=8)
                cnt++;
            else
                {
                    char temp = '0'+cnt;
                    ans+=temp;
                    ans+=word[i-1];
                    prev = word[i];
                    cnt = 1;
                }
        }

        // checking for last char append 
        if(cnt > 0 )
        {
            char last_char = word[n-1];
            char temp = '0'+cnt;

            ans+=temp;
            ans+=last_char;
        }

        return ans;
    }
};