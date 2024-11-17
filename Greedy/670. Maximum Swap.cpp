/*
Leetcode Link : https://leetcode.com/problems/maximum-swap/description/
*/


// t.c : O(n) and s.c : O(n) 
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        
        vector<int>maxRight(n);
        maxRight[n-1] = n-1;

        for(int i=n-2;i>=0;i--){
            int rightMaxIdx = maxRight[i+1];
            int rightMaxEle = s[rightMaxIdx];

            maxRight[i] = s[i] > rightMaxEle ? i : rightMaxIdx;

        }

        for(int i=0;i<n;i++){

            int maxRightIdx = maxRight[i];
            int maxRightEle = s[maxRightIdx];
            if(s[i] < maxRightEle)
            {
                swap(s[i],s[maxRightIdx]);
                return stoi(s);
            }
        }

        return num;
    }


};