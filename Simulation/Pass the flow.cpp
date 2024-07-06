/*
Leetcode Link : https://leetcode.com/problems/pass-the-pillow/description
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        int temp = 1;
        int dir = 1;
        while(time > 0)
        {
            if(temp==n || temp==1)
            {
                if(temp==n)
                {
                    temp=n-1;
                    dir =  0;
                }
                else
                {
                    temp = 2;
                    dir = 1;
                }
            }
            else if(dir == 1)
                temp++;
            else
                temp--;

            time--;
        }
        return temp;
    }
};