class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==0) return;
         
        queue<pair<int,int>> q;
        //push all 0's in queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)//gate
                {
                    q.push({i,j});
                }
            }
        }
        vector<int> dir={0,1,0,-1,0};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int k=0;k<=3;k++){
                int nx=x+dir[k];
                int ny=y+dir[k+1];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==2147483647){
                    grid[nx][ny]=1+grid[x][y];
                    q.push({nx,ny});
                }

            }
        }
        
    }
};
