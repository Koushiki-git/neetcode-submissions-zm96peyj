class Solution {
private:
    void dfs(int node,vector<vector<int>>&adj,vector<int> &vis){
        //mark node as visited
        vis[node]=1;
        
        //traverse the neighbours of node
        for(auto &nbr:adj[node]){
            if(!vis[nbr]){
                dfs(nbr,adj,vis);
            }

        }

    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //BUILD THE ADJ LIST
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        int components=0;
        vector<int> vis(n,0);


        //the no. of componenets is the number of times the dfs is started
        for(int i=0;i<n;i++){
            if(!vis[i]){
                components++;
                dfs(i,adj,vis);
            }
        }
        return components;

    }
};
