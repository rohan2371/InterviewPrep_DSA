/*
Leetcode Link : https://leetcode.com/problems/candy/description/
*/

class Solution {
public:
    int n;
    int solOne(vector<int>&ratings)
    {
        vector<int>L2R(n,1);
        vector<int>R2L(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                L2R[i] = L2R[i-1]+1;
        }

        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                R2L[i]=R2L[i+1]+1;
        }

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans+=max(L2R[i],R2L[i]);
        }

        return ans;


    }
    int candy(vector<int>& ratings) {
        n = ratings.size();
        return solOne(ratings);
    }
};