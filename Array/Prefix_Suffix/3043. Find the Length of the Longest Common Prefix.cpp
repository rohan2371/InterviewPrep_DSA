/*
Leetcode Link : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/
*/

// t.c : O(n*k) , s.c : O(n*k)
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;

        // building possible prefix hashset
        for(int i=0;i<arr1.size();i++){
            string prefix="";
            string num = to_string(arr1[i]);
            for(char ch : num){
                prefix+=ch;
                st.insert(prefix);
            }
        }

        int maxLen = 0;
        for(int i=0;i<arr2.size();i++){
            string prefix = "";
            string num = to_string(arr2[i]);
            for(char ch : num){
                prefix+=ch;
                if(st.find(prefix)!=st.end())
                    maxLen = max(maxLen,prefix.length()); 
            }
        }

        return maxLen;
    }

    int max(int a,int b)
    {
        if(a>b)
            return a;
        return b;
    }
};