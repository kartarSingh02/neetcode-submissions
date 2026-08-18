class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        int nrow[4] = {-1,0,1,0};
        int ncol[4] = {0,-1,0,1};

        while(!q.empty()){
            auto[i,j] = q.front();
            q.pop();

            for(int k = 0; k < 4 ;k++){

                int row = i + nrow[k];
                int col = j + ncol[k];

                if(row >= 0 && row<n && col>=0 && col<m && grid[row][col] == INT_MAX){
                    grid[row][col] = grid[i][j] + 1;
                    q.push({row,col});
                }
            }
        }
    }
};
