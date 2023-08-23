/*
    LeetCode link : https://leetcode.com/problems/reorganize-string/
*/

// Approach 1 : using max_heap -> priority_queue 
// t.c : o(k * log(k)) or worst case t.c : o(n*log(n))
class Solution {
public:
    typedef pair<int,char>p;
    string reorganizeString(string s) {
        int n = s.length();
        vector<int>count(26,0);
        for(char &ch : s)
        {
            count[ch-'a']++;
            if(count[ch-'a'] > (n+1)/2)
                return "";
        }

        priority_queue<p,vector<p>>pq;
        for(char ch='a'; ch<='z';ch++)
        {
            if(count[ch-'a'] > 0)
                pq.push({count[ch-'a'],ch});
        }

        string result = "";
        // t.c : o(k * log(k))
        // worst case : o(n * log(n))
        while(pq.size()>=2)
        {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            result.push_back(p1.second);
            result.push_back(p2.second);
            p1.first--;
            p2.first--;

            if(p1.first>0)
                pq.push(p1);
            if(p2.first>0)
                pq.push(p2);
        }

        if(!pq.empty())
        {
            result.push_back(pq.top().second);
        }
        return result;

    }
};


// Approach 2 

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int>count(26,0);
        int maxFreq =0;
        int charMaxFreq;
        for(char &ch : s)
        {
            count[ch-'a']++;

            if(count[ch-'a'] > maxFreq)
            {
                maxFreq = count[ch-'a'];
                charMaxFreq = ch;
            }
            if(count[ch-'a'] > (n+1)/2)
                return "";
        }

        string result = s;
        int i=0;


        // Max char freq ko alternate positions mai daal diya 
        while(count[charMaxFreq-'a'] > 0)
        {
            result[i] = charMaxFreq;
            i+=2;// ALTERNATE
            count[charMaxFreq-'a']--;
        }
        // place rest of the letters in empty slots in alternate positions 

        for(char ch ='a' ;ch<='z';ch++)
        {
            while(count[ch-'a']>0){
                if(i>=n)
                    i=1;
                result[i] = ch;
                i+=2;
                count[ch-'a']--;
            }
        }
        return result;
    }
};