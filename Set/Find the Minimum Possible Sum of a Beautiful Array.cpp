/*
Leetcode Link : https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array/description/?envType=list&envId=92acilc2
*/

class Solution {
public:
    
    long long minimumPossibleSum(int n, int target) {
        set<long long >st;
        long long sum = 0;
        long long num = 1;
        while(n){
            if(st.find(num)==st.end()){
                sum+=num;
                st.insert(num);
                st.insert(target-num);
                n--;
            }
            num++;
        }
        return sum;
    }
};