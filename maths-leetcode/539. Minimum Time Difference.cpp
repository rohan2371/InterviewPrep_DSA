/*
Leetcode Link : https://leetcode.com/problems/minimum-time-difference/description/
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>vec(n,0);
        for(int i=0;i<n;i++){
             string temp = timePoints[i];
             int hours = stoi(temp.substr(0,2));
             int min = stoi(temp.substr(3,2));
            
             int totalMin = 0;
            if(hours == 0 && min == 0)
                totalMin = 24*60;
            else if(hours == 0 && min != 0)
                totalMin = min;
            else
                totalMin = hours*60 + min;
                
            vec[i] = totalMin;
        }
        sort(begin(vec),end(vec));

        int minDiff = INT_MAX;
        for(int i=1;i<n;i++){
            int diff = vec[i]-vec[i-1];
            /*
            ["05:31","22:08","00:35"]
            [331 , 1320 , 35] -> minutes 
            midnight madhe ratri 10:08 and ratri 12:35 hai minimum difference 
            tya sati fakt hai navin conditions add kelo 

            diff = 1320 - 35 = 1297 
            maxDiff = 1440 - 1297 -> 147 

            */
            if(diff > 12 * 60)
                minDiff = min(24*60 - diff , minDiff); 
            else
                minDiff = min(vec[i]-vec[i-1],minDiff);
        }

        int last = vec[n-1]-vec[0];
        if(last > 12*60)
            minDiff = min(24*60-last, minDiff);
        return minDiff;
    }
};