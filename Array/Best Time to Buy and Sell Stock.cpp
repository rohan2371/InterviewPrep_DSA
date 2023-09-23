/*
Leetcode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

// t.c : O(n) , s.c : O(1);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min = INT_MAX;

        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min)
                min = prices[i];
            
            else if(prices[i]-min > max_profit)
                max_profit = prices[i]-min;
        }
        return max_profit;
    }
};