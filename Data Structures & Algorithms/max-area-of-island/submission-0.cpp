class Solution {
private:
    int bfs(vector<vector<int>>& grid,int i, int j){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=0;//visited
        int area=1;
         
        vector<int> dir={0,1,0,-1,0};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int k=0;k<=3;k++){
                int ni=x+dir[k];
                int nj=y+dir[k+1];
                if(ni>=0 && nj>=0 && ni<n && nj<m &&grid[ni][nj]==1)
                {
                    grid[ni][nj]=0;
                    area++;
                    q.push({ni,nj});
                }
            }
        }

       
        
        return area;

    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxa=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxa=max(maxa,bfs(grid,i,j));
                }
            }
        }
        return maxa;
        
    }
};
