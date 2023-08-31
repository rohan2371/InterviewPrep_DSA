/*
Leetcode Link : https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/
*/

/*
Three facts to solve this questions 
fact 1 : 
 num = 12 if we divide this number by  5,3,4 then operations = parts-1;
 we first divide number 5,7 then next step 5,3,4 
 so total number of operations is 2 and parts are 3 


 fact 2 : arr = {1,2,11,3} 
 here we want to divide 11 such that he should be less than equal to 3 that to in minimum number of operations 

 the best way divide we that number with next element 
 parts = 11/3 -> 3
 if(11%3!=0)
    parts ++;  -> parts -> 4

 3,3,3,2 -> here u can see 4 parts there is multiple ways to divide a number but for the minimum operations we need to follow this fact  
 and opertions = parts-1 ->3

 let's suppose arr = {1,2,3,11,5}
 parts = 11/5 -> 2 
 if(11%5 !=0)
    parts++  -> parts -> 3 

5,5,2 
operations = parts-1 -> 2


fact 3 : {9,7,6 }

now we want to divide 7 such that is should be less than equal to 6 
we can divide like 1,6
                   2,5
                   3,4

if we take first 1,6 then 
{9,1,6,6} to convert 9 less than 1 thant i need to divide with by 1 , then {1,1,1,1,1,1,1,1,1} 
so number of operations will increased we have to with minimum number of operations 
so there is better way to decide which number we should take 

parts = 7/6 = 1 
if(7%6 !=0)
    parts++; -> parts = 2

7/parts = 7/2 = 3 
we should take 3 in nums[i]


*/
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long operations  = 0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=nums[i+1])
                continue;
            
            int parts = nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]!=0)
                parts++;
            
            operations += parts - 1;
            nums[i] = nums[i]/parts;
        }
        return operations;
    }
};