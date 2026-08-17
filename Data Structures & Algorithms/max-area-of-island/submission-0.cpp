class Solution {

private:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
    int n = grid.size();
    int m = grid[0].size();
    vis[i][j]=true;
    int area = 1;
    
    int nrow[4]={-1,0,1,0};
    int ncol[4]={0,1,0,-1};

    for(int k=0; k<4; k++){
        int row = nrow[k]+i;
        int col = ncol[k]+j;

        if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0 && grid[row][col]==1){
            area+=dfs(grid, row, col, vis);
        }
    }
    return area;
}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int ans = dfs(grid, i, j, visited);
                    maxArea = max(maxArea, ans);
                }
            }
        }
        return maxArea;
    }
};
