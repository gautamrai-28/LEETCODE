class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<char>> &grid, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || grid[i][j] == '0') 
           return;
        
        vis[i][j] = true;

        dfs(i-1,j,vis,grid,n,m); //top
        dfs(i,j-1,vis,grid,n,m); //bootom
        dfs(i+1,j,vis,grid,n,m); //left
        dfs(i,j+1,vis,grid,n,m); //right
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis (n, vector<bool> (m, false));
        int isLand = 0;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(i,j,vis,grid,n,m);
                    isLand++;
                }
            }
        }

        return isLand;
    }
};