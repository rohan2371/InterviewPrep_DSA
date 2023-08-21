/*
    Company Tags  : Flipkart, Amazon, Samsung, MakeMyTrip, Oracle, Adobe
    Question Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycleDfs(vector<int>adj[],int u,vector<bool>&visited,int parent)
    {
        visited[u] = true;
        
        for(int &v : adj[u])
        {
            if(v==parent)   continue;
            
            if(visited[v])
                return true;
            
            if(isCycleDfs(adj,v,visited,u))
                return true;
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && isCycleDfs(adj,i,visited,-1))
                return true;
        }
        return false;
    }
};