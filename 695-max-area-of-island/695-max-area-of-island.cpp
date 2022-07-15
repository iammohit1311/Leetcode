class Solution {
    int n , m;
    int dfs(int i , int j , vector<vector<int>>& grid,vector<vector<int>>&vis){
        if(i < 0 or i >= n or j < 0 or j >= m or vis[i][j] != 0 or grid[i][j] != 1){
            return 0;
        }  
        
        vis[i][j] = 1;
        return 1+dfs(i+1,j, grid, vis)+dfs(i-1,j,grid,vis)+dfs(i,j+1,grid, vis)+dfs(i, j-1,grid,vis);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int area = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j]){
                    area = max(area, dfs(i, j, grid, vis));
                }
            }
        }
        return area;
        
    }
};