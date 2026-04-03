class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        //count the fresh ones and enqueue the rot
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;

        //bfs
        int min=-1;
        vector<int> dir={0,1,0,-1,0};
        while(!q.empty()){
            int sz=q.size();
            min++;
            while(sz--){
                auto[x,y]=q.front();
                q.pop();
                for(int k=0;k<=3;k++){
                    int nx=x+dir[k];
                    int ny=y+dir[k+1];
                    if(nx>=0 && ny>=0 && nx<n &&ny<m && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }

            }
            
        }
        return (fresh==0)?min:-1 ;
        
    }
};
