class Solution {
private:
    void dfs(vector<vector<char>>& grid,int i, int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';//sink island

        //explore all 4 dir
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);

    }
private:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0'; // mark visited

        vector<int> dir = {0,1,0,-1,0};

        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();

            for(int k=0; k<4; k++) {
                int nx = x + dir[k];
                int ny = y + dir[k+1];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1') {
                    grid[nx][ny] = '0';
                    q.push({nx,ny});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int num=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    num++;
                    bfs(grid,i,j);//sink the island
                }

            }
        }
        return num;
        
    }
};
