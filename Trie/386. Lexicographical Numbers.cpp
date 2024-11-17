/*
Leetcode Link : https://leetcode.com/problems/lexicographical-numbers/description/
*/

// t.c : O(n) and s.c : O(1)
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>result;
        
        for(int start=1; start <= 9;start++){
            solve(start,n,result);
        }
        return result;
    }

    void solve(int curr, int n ,vector<int>&result)
    {
        if(curr > n)
            return ;
        
        result.push_back(curr);

        for(int appd = 0;appd <=9;appd++){
             int newNum = curr*10 + appd;
             if(newNum > n)
                return ;
            solve(newNum , n , result);

        }
    }
};