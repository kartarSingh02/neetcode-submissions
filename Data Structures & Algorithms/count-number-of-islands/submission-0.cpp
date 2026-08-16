class Solution {
public:
    int n, m;
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& vis){
        vis[i][j]=1;
        
        int nrow[4]={-1,0,1,0};
        int ncol[4]={0,1,0,-1};

        for(int k=0; k<4; k++){
            int row = nrow[k]+i;
            int col = ncol[k]+j;

            if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0 && grid[row][col]=='1'){
                dfs(grid, row, col, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    ans++;
                    dfs(grid, i, j, vis);
                }
            }
        }

        return ans;
    }
};