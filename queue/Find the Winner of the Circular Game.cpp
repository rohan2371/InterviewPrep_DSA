/*
Leetcode link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
*/

// t.c : o(n*k)
// s.c : o(n)
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }

        int cnt = 1;
        while(q.size() > 1)
        {
            if(cnt==k){
                q.pop();
                cnt = 1;
            }
            else{
                int val = q.front();
                q.pop();
                q.push(val);
                cnt++;
            }
        }
        return q.front();
    }
};