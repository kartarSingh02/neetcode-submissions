class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // {{row,col}, time}
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        int freshCount = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0}); //initaly it will be 0 time/unit na
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1){
                    freshCount++; // fresh fruits
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int count = 0; 
        int tm = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            tm = max(tm,t);    
            q.pop();

            for(int k=0;k<4;k++){
                int row = r+drow[k];
                int col = c+dcol[k];

                if(row>=0 && row<n && col>=0 && col<m && vis[row][col] == 0 && grid[row][col] == 1){
                    q.push({{row,col},t+1});
                    vis[row][col] = 2;
                    count++;
                }
            }

        }

        if(count != freshCount) return -1;
        return tm;
    }
};
