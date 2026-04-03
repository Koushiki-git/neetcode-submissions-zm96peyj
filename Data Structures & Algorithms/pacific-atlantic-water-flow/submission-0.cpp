class Solution {
public:
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));
        vector<vector<int>> ans;

        // DFS from Pacific (top row + left col)
        for (int i = 0; i < n; i++) dfs(heights, pac, i, 0);
        for (int j = 0; j < m; j++) dfs(heights, pac, 0, j);

        // DFS from Atlantic (bottom row + right col)
        for (int i = 0; i < n; i++) dfs(heights, atl, i, m - 1);
        for (int j = 0; j < m; j++) dfs(heights, atl, n - 1, j);

        // Collect results
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int r, int c) {
        if (ocean[r][c]) return; // already visited
        ocean[r][c] = 1;

        vector<int> dir = {0, 1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k];
            int nc = c + dir[k + 1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(heights, ocean, nr, nc);
            }
        }
    }
};
