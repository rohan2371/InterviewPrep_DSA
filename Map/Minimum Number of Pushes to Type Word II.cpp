/*
Leetcode link : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
*/

class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        for(auto it : word)
        {
            mp[it]++;
        }
        
        vector<pair<char,int>>vec;
        for(auto it : mp)
        {
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),cmp);
        mp.clear();
        int res = 0;
        for(int i=1;i<=vec.size();i++)
        {
            if(i<=8)
            {
                res+=vec[i-1].second;
            }
            else if(i<=16)
            {
                res+=2*vec[i-1].second;
            }
            else if(i<=24)
            {
                res+=3*vec[i-1].second;
            }
            else
                res+=4*vec[i-1].second;
        }

        return res;
    }
   
    

     static bool cmp(pair<char,int>&p1,pair<char,int>&p2)
    {
        if(p1.second > p2.second)
            return true;
        return false;

    }
};