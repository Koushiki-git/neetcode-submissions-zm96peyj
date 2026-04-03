class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        //create an adj list
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            if(u>V || v>V){
                return false;
            }
            adj[v].push_back(u);//directed graph

        }

        //we'll use topo sort
        int indeg[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indeg[it]++;

            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==V) return true;
        return false;


            
        
        
    }
};
