/*
Leetcode Link : https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/
*/


class Solution {
public:
    int minimumSum(int n, int k) {
        // n=5,k =4 
        // initally we start with i = 1 ,insert in the set
        // we also insert (k-i) element in the set 
        // reason is simple if i insert i = 1, and again insert 
        // (k-i) -> (4-1) -> 3 , insert in the set 
        // set -> 1,3
        // i = 2, set -> 1,3,2 
        // also insert(k-i) = (4-2) , 
        // updated set-> 1,3,2,4
        // i = 3,
        // we first check whether element is present in set or not 
        // if element is present then skip the element also skip sum of 
        // this element 

        set<int>st;
        int num = 1;
        int sum = 0;
        while(n>0){
            if(st.find(num) == st.end()){
                sum+=num;
                st.insert(num);
                st.insert(k-num);
                n--;
            }
            num++;
        }

        return sum;
    }

};
