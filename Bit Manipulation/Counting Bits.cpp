/*
Leetcode link : https://leetcode.com/problems/counting-bits/description
*/

// t.c : o(n*log(n)) , s.c : n*32
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            bitset<32>temp(i);
            ans.push_back(temp.count());
        }
        return ans;
    }
};



// t.c : o(n*log(n)) s.c : o(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            
             int j = i;
             unsigned int cnt = 0;
             while(j){
                 cnt+= j & 1;
                 j = j>>1;
             }
             ans.push_back(cnt);
        }
        return ans;
    }
};


// same solution as above only difference way to write 
class Solution {
public:
    vector<int> countBits(int n) {
       
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
             int cnt = 0;
            for(int j=0;j<32;j++)
            {
                if( (i & (1<<j))!=0)
                    cnt++;
            }
            
            ans.push_back(cnt);
        }
        
       return ans;
    }
};


/*
write 1 to 10 and all it's binary format 

1 - 1            6 - 110
2 - 10           7 - 111
3 - 11           8 - 1000
4 - 100          9 - 1001
5 - 101         10 - 1010

let's count no set or 1bits in 4 -> 1   and 4/2 = 2  bits also 1 
lets check with 6 1bits = 2 and 3 1bits = 2 , 
10 1bits = 2 ,10/2 = 5 1bits = 2 
check it is observations we find that jo be number ko divided by 2 karoge to 1 bits to same hi rahenge 

now for the odd number of observations
 oddnum/2 + 1  we get no of 1bits 
 9/2 +  1  = 4 1bits + 1 = 1+1 = 2 

 now for the 7th 
 7/2 = 3 1bits = 2  + 1 = 3 
*/


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1);
        if(n==0)
            return res;
        
        for(int i=1;i<=n;i++){
            if(i%2!=0){
                res[i] = res[i/2] + 1;
            }else{
                res[i] = res[i/2];
            }
        }
        return res;
    }
};