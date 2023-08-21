/*
     Leetcode Link : https://leetcode.com/problems/repeated-substring-pattern/description/
     Company tag :  AMAZON, GOOGLE
*/

// T.C  : o(n * root(n))
/*
  The "if(n%l == 0)" body will only run for divisors of n. 
  There can be 2*root(n) divisors of a number n.
  Inside if condition, we call substr which takes n and also run a for loop for n/l times ----- n + n/l ~ O(n)

  So, Time complexity becomes = O(2* root(n) * n)  ~~ O(n * root(n))
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       int n = s.size();
        for(int i=n/2;i>=1;i--)
        {
            
            if(n%i == 0)
            {
               int times = n/i;
               string pattern = s.substr(0,i);
               string newStr = "";

               while(times--){
                   newStr+=pattern;
               }
               if(newStr == s)
                    return true;
                
            }
            
        }
        
        return false;
    }
};