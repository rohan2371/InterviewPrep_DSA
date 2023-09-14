/*
Leetcode Link : https://leetcode.com/problems/reconstruct-itinerary/description/
*/

//Approach-1 (Using adj of string to vector and sorting it)
//T.C : O(V^2)


class Solution {
public:
    vector<string>res;
    unordered_map<string,vector<string>>adj;
    int numTickets;

    bool DFS(string fromAirport,vector<string>&path)
    {
        path.push_back(fromAirport);
        if(path.size() == numTickets+1)
        {
            res = path;
            return true;
        }

        vector<string>& neighbors = adj[fromAirport];
        for(int i=0;i<neighbors.size();i++)
        {
            string toAirport = neighbors[i];
            // remove kardo abhi k liye 
            neighbors.erase(neighbors.begin()+i);
            if(DFS(toAirport,path) == true)
            {
                return true;
            }
            neighbors.insert(neighbors.begin()+i,toAirport);
        }
        path.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTickets = tickets.size();
        for(auto &it : tickets) 
        {
            string u = it[0];
            string v = it[1];
            adj[u].push_back(v);
        }

        // sorting lexical 
        for(auto &it : adj)
        {
            sort(begin(it.second),end(it.second));
        }
        vector<string>path;
        DFS("JFK",path);
        return res;
    }
};