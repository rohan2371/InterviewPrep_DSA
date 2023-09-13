/*
Leetcode Link : https://leetcode.com/problems/combination-sum/description/
*/

class Solution {
public:
    int n;

    void rec(vector<int>&candidates,vector<int>&ds,vector<vector<int>>&res,int target,int idx)
    {
        if(idx==n){
            if(target==0){
                res.push_back(ds);
            }
            return ;
        }
        else
        {
            if(candidates[idx]<=target){
                ds.push_back(candidates[idx]);
                rec(candidates,ds,res,target-candidates[idx],idx);
                ds.pop_back();
            }
            
            rec(candidates,ds,res,target,idx+1);
        }
    }      
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>>res;
        vector<int>ds;
        rec(candidates,ds,res,target,0);
        return res;
    }
};