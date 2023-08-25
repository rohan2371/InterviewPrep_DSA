/*
Leetcode Link : https://leetcode.com/problems/text-justification/description/
Company Tags                : GOOGLE
*/

// time complexity : o(n*k)

class Solution {
public:
    int MAX_WIDTH;
    string findLine(vector<string>&words,int i,int j,int eachWordSpace,int extraSpace)
    {
        string line = "";
        for(int k=i;k<j;k++)
        {
            line+=words[k];

            if(k==j-1)
                continue;
            for(int z=1;z<=eachWordSpace;z++)
            {
                line+=" ";
            }

            if(extraSpace > 0){
                line+=" ";
                extraSpace--;
            }
        }
        while(line.size()< MAX_WIDTH){
            line+=" ";
        }
            
        return line;

    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        int n = words.size();
        vector<string>result;
        MAX_WIDTH = maxWidth;
        while(i<n)
        {
            int spaceSlots = 0;
            int lettersCount = words[i].length();
            int j=i+1;
            while(j<n && spaceSlots+words[j].length()+lettersCount+1<=maxWidth)
            {
                spaceSlots+=1;
                lettersCount+=words[j].length();
                j++;
            }
            int remainingSlots = maxWidth-lettersCount;

            int eachWordSpace = spaceSlots==0?0:remainingSlots/spaceSlots;
            int extraSpace = spaceSlots==0?0:remainingSlots%spaceSlots;
            if(j==n){  // means we are in last line -> left justified
                eachWordSpace = 1;
                extraSpace = 0;
            }
            string line = findLine(words,i,j,eachWordSpace,extraSpace);
            result.push_back(line);
            i=j;
        }

        
        return result;
    }
    
};