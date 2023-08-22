/*
LeetCode Link : https://leetcode.com/problems/excel-sheet-column-title/description/
*/
/*
the main part of the code is if(rem==0) num--
why -> if num = 26 then op : z
but our program op was  : za
so 26/26 = 1 
our loop checking is(num>0) after perfect division we should minun -1 to num 
to get correct results 
*/
class Solution {
public:
  
    string convertToTitle(int columnNumber) {
          map<int,char>mp;
    char key = 'A';
    for(int i=1;i<26;i++)
    {
        mp[i] = key++;
    }
    mp[0] = 'Z';
        string ans = "";
        
        while(columnNumber>0)
        {
            int rem = columnNumber%26;
            ans+=mp[rem];
            if(rem==0)
                columnNumber--;
            columnNumber = columnNumber/26;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

