/*

Leetcode Link : https://leetcode.com/problems/most-profit-assigning-work/description/

*/

// brute force solution
// t.c : o(n^2)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        int ans = 0;
        for(int i=0;i<m;i++)
        {
            int max_prof = 0;
            for(int j=0;j<n;j++)
            {
                if(worker[i]>=difficulty[j])
                {
                    if(profit[j]>=max_prof)
                        max_prof= profit[j];
                }
            }
            ans+=max_prof;
        }

        return ans;

    }
};


// 2nd solution using max heap
// s.c : o(n)

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        priority_queue<pair<int,int>>pq;
        // o(nlogn)
        for(int i=0;i<n;i++)
        {
            pq.push({profit[i],difficulty[i]});
        }
        // sort descending order : O(mlogm)
        sort(worker.begin(),worker.end(),greater<int>());

        int total_profit =  0;
        int i=0;

        // O(m*log(n))
        while(i<m && !pq.empty())
        {
            if(worker[i]>=pq.top().second)
            {
                total_profit+=pq.top().first;
                i++;
            }
            else
                pq.pop();
        }
        return total_profit;
    }
};


// binary search 
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();    

        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({difficulty[i],profit[i]});
        }
        sort(begin(vec),end(vec));

        // Pre processing to find maximum profit till index i at constant time 
        for(int i=1;i<vec.size();i++)
        {
            vec[i].second = max(vec[i].second , vec[i-1].second);
        }

        int totalProfit = 0;
        for(int i=0;i<m;i++)
        {
            int workerDiffLevel = worker[i];
            
            // apply binary search
            int l =0, r = vec.size()-1;
            int maxProfit = 0;

            while(l <= r) {
                int mid = l + (r-l)/2;

                if(workerDiffLevel >= vec[mid].first){
                    maxProfit = max(maxProfit,vec[mid].second);
                    l = mid + 1;
                }else{
                    r = mid-1;
                }
            }

            totalProfit += maxProfit;
        }
        return totalProfit;


    }
};
