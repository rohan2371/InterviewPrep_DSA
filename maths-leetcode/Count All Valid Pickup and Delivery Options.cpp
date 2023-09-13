/*
Leetcode Link : https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

*/

/*
Pickup should before the develivery 
n = 1 
op : 1 
explination : P1D1 only one possiblilty 

n = 2 
op : 6 
explination : P1P2D1D2 , P1P2D2D1 , P1D1P2D2 , P2P1D1D2 , P2P1D2D1 , P2D2P1D1 


brute force solution is create array of P1P2D1D2 and find all combinations return the answer but 
time complexity would be n! that is not acceptable

intution :  n = 1 , op = 1,  P1D1 

            n = 2 , op 6 
            _P1_D1_  , so in this space i need to add P2D2  , spaces = 3 

        combinations in space 1 : P2D2P1D1 , P2P1D2D1 , P2P1D1D2 
        combinations in space 2 : P1P2D2D1 , P1P2D1D2 
        combinations in space 3 : P1D1P2D2 

        3 + 2 + 1 = 6 -> sum of n natural number formula  = n*(n+1)/2 
        
        n = 3 , op : 90 

        _P2_D2_P1_D1_ 
        5+4+3+2+1 = 15 combinations possible onlye for P2D2P1D1 so there 5 more combinations left for n=2
        15*6 = 90 combinations possible  

        space formula : (n-1)*2 + 1;

*/


class Solution {
public:
    int M = 1e9+7;
    int countOrders(int n) {
        if(n==1)
            return 1;
        
        long long result = 1;
        for(int i=2;i<=n;i++)
        {
            int spaces = (i-1)*2 + 1;
            int currPossibility = spaces * (spaces+1)/2;
            result *=currPossibility;
            result = result%M;
        }
        return result;
    }
};