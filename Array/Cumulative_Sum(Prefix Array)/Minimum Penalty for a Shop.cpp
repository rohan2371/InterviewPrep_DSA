class Solution {
public:
    // t.c : o(n^2) , s.c : o(1)
    int sol1(string customers){
        int n = customers.size();
        int minPenalty = INT_MAX;
        int minHour = INT_MAX;

        for(int i=0;i<n;i++){
            int j = i-1;
            int penalty = 0;
            // left side shop open check if customers not come then penalty 1
            while(j>=0){
                if(customers[j]=='N')
                    penalty++;
                j--;
            }
            // check right side here i is includede shop is closed and if customers
            // came then penalty 
            int closed = i;
            while(closed<n){
                if(customers[closed]=='Y')
                    penalty++;
                closed++;
            }

            if(penalty < minPenalty){
                minPenalty = penalty;
                minHour = i;
            }
        }

        // trying to close at nth hour 
        // 0 to n-1 shop is open
        int nthHourPenalty = count(customers.begin(),customers.end(),'N');
        if(nthHourPenalty < minPenalty)
        {
            minPenalty=nthHourPenalty;
            minHour = n;
        }
        return minHour;
    }

    // t.c : o(n) , s.c : o(n)
    int bestClosingTime(string customers) {
        int n = customers.size();
        // prefix part where shop is open
        // starting from left side
        vector<int>prefixN(n+1,0);
        prefixN[0] = 0;

        // suffix part where shop is closed here i is included 
        //  starting from right side 
        vector<int>suffixY(n+1,0);
        suffixY[n] = 0;

        for(int i=1;i<=n;i++){
            if(customers[i-1]=='N')
                prefixN[i] = 1  + prefixN[i-1];
            else
                prefixN[i] = prefixN[i-1];
        }

        for(int i=n-1;i>=0;i--){
            if(customers[i] == 'Y')
                suffixY[i] = suffixY[i+1] + 1;
            else 
                suffixY[i] = suffixY[i+1];
        }

        int minPenalty = INT_MAX;
        int minHour = INT_MAX;

        for(int i=0;i<=n;i++){
            int currPenalty = prefixN[i]+suffixY[i];
            if(currPenalty<minPenalty){
                minPenalty = currPenalty;
                minHour = i;
            }
      }

      return minHour;



    }
};

// t.c : o(n) , s.c : o(1)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = count(customers.begin(),customers.end(),'Y');
        int minPenalty = penalty;
        int minHour = 0;

        for(int i=0;i<n;i++){
            if(customers[i] == 'Y')
                penalty--;
            else
                penalty++;

            if(minPenalty > penalty){
                minPenalty = penalty;
                minHour = i+1;
            }
        }
        return minHour;
    }
};