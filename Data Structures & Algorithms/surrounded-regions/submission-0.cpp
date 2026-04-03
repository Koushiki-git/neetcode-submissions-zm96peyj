class Solution {
private:
    void dfs(int r,int c,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();

        //boundary check
        if(r<0 || c<0 ||r>=n || c>=m || board[r][c]!='O') return ;

        board[r][c]='#';//found '0' cell

        //check 4 directions
        dfs(r+1,c,board);
        dfs(r-1,c,board);
        dfs(r,c+1,board);
        dfs(r,c-1,board);

    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        if(n==0) return;
        //start from the boundary cells
        //first and last column
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][m-1]=='O') dfs(i,m-1,board);
        }
        //first and last row
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') dfs(0,j,board);
            if(board[n-1][j]=='O') dfs(n-1,j,board);
        }

        //flip surrounded 0 with X
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
                
            }
        }
    }
};
