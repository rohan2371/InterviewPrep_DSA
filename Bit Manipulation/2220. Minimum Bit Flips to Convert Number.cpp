/*
Leetcode link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
*/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal; // xor operation give use all bit difference as 1
        
        int cnt = 0 ;

        while(xorResult > 0)
        {
            cnt+= xorResult & 1;
            xorResult >>= 1;// right shift by 1
        } 
        return cnt;
    }
};