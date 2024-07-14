/*
Leetcode link : https://leetcode.com/problems/maximum-score-from-removing-substrings/description/
*/


class Solution {
public:

    int maximumGain(string s, int x, int y) {
        string maxStr = x > y ? "ab" : "ba";
        string minStr = x < y ? "ab" : "ba";

        int res = 0;

        string ans1 = solve(s,maxStr);
        res+=(s.length()-ans1.length())/2 * max(x,y);

        string ans2 = solve(ans1,minStr);
        res+= (ans1.length() - ans2.length())/2 * min(x,y);

        return res;

    }

    string solve(string s , string maxStr)
    {
        stack<char>st;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]==maxStr[1] && st.size()>0 && st.top()==maxStr[0])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        string temp = "";
        while(st.size()>0){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};