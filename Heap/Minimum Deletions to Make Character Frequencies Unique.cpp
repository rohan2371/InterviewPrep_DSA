/*
Leetcode Link : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

*/


class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto &it : s)
        {
            mp[it]++;
        }
        unordered_set<int>unique;
        int cnt = 0;
        for(auto &it : mp)
        {
            while(it.second != 0 && unique.find(it.second) != unique.end())
            {
                it.second--;
                cnt++;
            }
            unique.insert(it.second);
        }
        return cnt;
    }
};










class Solution {
public:
    int minDeletions(string s) {
        int freq[26] ={0};
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        sort(begin(freq),end(freq));
        int cnt = 0;
        for(int i=24;i>=0 && freq[i]>0 ;i--)
        {
            if(freq[i]>=freq[i+1])
            {
                int prev = freq[i];
                freq[i] = max(0,freq[i+1]-1);
                cnt+=prev-freq[i];
            }
            
        }
        return cnt;
    }
};