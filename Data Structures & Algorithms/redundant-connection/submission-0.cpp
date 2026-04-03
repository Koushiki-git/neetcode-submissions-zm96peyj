class Solution {
public:
    vector<int> parent,rank;

    int findParent(int x){
        if(parent[x]!=x) parent[x]=findParent(parent[x]);
        return parent[x];//base case

    }
    
    //Union by Rank
    bool unionset(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv) return false;//already connected
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;

        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
            
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
        return true;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;//initially every node is its own parent
        }

        for(auto &e:edges){
            int u=e[0],v=e[1];
            if(unionset(u,v)==false){
                return e;//e is a vector. e={e[0],e[1]}
            }
        }
        return {};

        
    }
};
