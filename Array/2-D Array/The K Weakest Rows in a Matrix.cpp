/*
Leetcode Link : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
*/

class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        return p1.second < p2.second;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>vec;
        
        for(int i=0;i<mat.size();i++)
        {
            pair<int,int>p;
            p = make_pair(i,0);
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                    p.second++;
            }
            vec.push_back(p);
        }
        sort(begin(vec),end(vec),cmp);
        for(auto &it : vec)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};