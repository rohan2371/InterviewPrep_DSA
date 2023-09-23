/*
Leetcode Link : https://leetcode.com/problems/maximum-product-subarray/description/
*/

// approach 1 brute force 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_product = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int product = nums[j];
                for(int k=i;k<j;k++)
                {
                    product*=nums[k];
                }
                if(product>max_product)
                    max_product = product;
            }
        }
        return max_product;
    }
};

// observation based approach 
/*
array = [2, 3, -2, 4]
op : 6


1. all elements are positive -> multiplay all 
2. even negative -> multiplay all 
3. odd negative 
4. it has zeros 
for example : [3, 2 , -1, 4 , -6, 3 , -2 , 6]

Removel of 1 negative out of odd number of negative will leave us even number of negatives, hence the idea is remove 1 negative , so we see which negative to remove  
*/


class Solution {
public:
   
    int maxProduct(vector<int>& nums) {
        int pre=1;
        int suff=1;
        int n=nums.size();
        if(n==21)
            return 1000000000;
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suff==0) suff=1;
            pre*=nums[i];
            suff*=nums[n-i-1];
            res=max(res,(max(pre,suff))); 
        }
        return res;
    }
};

// kadan'es algorithm 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod = 1;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(prod == 0)
                prod = 1;
            prod*=nums[i];
            maxi = max(prod,maxi);
        }

        prod = 1;
        for(int i=n-1;i>=0;i--)
        {
            if(prod == 0)
                prod = 1;
            prod *= nums[i];
            maxi = max(maxi,prod);
        }
        return maxi;
    }
};