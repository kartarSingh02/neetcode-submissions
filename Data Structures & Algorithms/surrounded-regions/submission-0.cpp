class Solution {

private:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis, int nrow[], int ncol[]){
        vis[i][j] = 1;
        int n = board.size();
        int m = board[0].size();
        for(int k=0;k<4;k++){
            int row = i + nrow[k];
            int col = j + ncol[k];

            if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && board[row][col] == 'O'){
                dfs(row, col, board, vis, nrow, ncol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        //check only borders if there O exists

        for(int j=0;j<m;j++){
            // for first row
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0,j,board,vis, nrow, ncol);
            }
            // last row
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1,j,board,vis, nrow, ncol);
            }
        }

        for(int i=0;i<n;i++){
            // first col
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,board,vis, nrow, ncol);
            }
            // last col
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,board,vis, nrow, ncol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
