/*
Leetcode link : https://leetcode.com/problems/number-of-atoms/description/
*/

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string,int>>st;
        st.push(unordered_map<string,int>());
        
        int i=0;
        while(i<n) {
            if(formula[i]=='(') {
                st.push(unordered_map<string,int>());
                i++;
            } else if(formula[i]==')') {
                unordered_map<string,int>curr = st.top(); // map at the top 
                st.pop();
                i++;
                string num;
                while((i<n) && isdigit(formula[i])){
                    num.push_back(formula[i]);
                    i++;
                }
                
                if(!num.empty()){
                    int mul = stoi(num);
                    for(auto it : curr ) {
                        int cnt = it.second;
                        string element = it.first;
                        curr[element] = cnt * mul;
                    }
                }

                // merging this to stack's top map
                for(auto &it : curr){
                    string element = it.first;
                    int count = it.second;
                    st.top()[element]+=count;
                }

            }else {
                string currElement;
                currElement.push_back(formula[i]);
                i++;
                while((i<n) && isalpha(formula[i]) && islower(formula[i])){
                    currElement.push_back(formula[i]);
                    i++;
                }
                string num;

                while((i<n) && isdigit(formula[i])){
                    num.push_back(formula[i]);
                    i++;
                }
                
                if(!num.empty()){
                    int cnt = stoi(num);
                    st.top()[currElement]+=cnt;
                }else
                    st.top()[currElement] += 1;
            }
        }

        // st will only have one element at top  (one map at top)

        map<string,int>sortedMap(begin(st.top()),end(st.top()));
        string result;
        for(auto &it : sortedMap){
            result+=it.first;
            int cnt = it.second;
            if(cnt > 1){
                result+=to_string(cnt);
            }
        }
        return result;
    }
};