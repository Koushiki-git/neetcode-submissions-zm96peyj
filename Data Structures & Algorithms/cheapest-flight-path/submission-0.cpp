class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //make the adj list
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            //u->{v,dist}
            adj[it[0]].push_back({it[1],it[2]});
        }
        //{stops,{node,dist}}
        queue<pair<int,pair<int,int>>> q;
        //using queue instaed of pq is also okay as stops increase sequentially
        //push src with dist=0
        q.push({0,{src,0}});

        //to store the min dist from src to all edges
        vector<int> dist(n,1e9);
        dist[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            
            if(stops>k) continue;//skip

            for(auto iter:adj[node]){
                int adjNode=iter.first;
                int edw=iter.second;
                //find the min dist to each node
                if(cost+edw <dist[adjNode]){
                    dist[adjNode]=cost+edw;
                    q.push({stops+1,{adjNode,cost+edw}});

                }

            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];

    }
};
