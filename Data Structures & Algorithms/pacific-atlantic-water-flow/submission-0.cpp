class Solution {
public:

void dfs(int r,int c,vector<vector<int>>& adj,vector<vector<bool>>& visited)
{
    visited[r][c]=true;
    int m=adj.size();
    int n=adj[0].size();
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    for(int k=0;k<4;k++)
    {
        int currX=r+dx[k];
        int currY=c+dy[k];
        if(currX >=0 && currX <m && currY >=0 && currY<n && !visited[currX][currY] && adj[currX][currY] >= adj[r][c]) 
        {
            dfs(currX,currY,adj,visited);
        }
    }

}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m= heights.size();
        int n=heights[0].size();
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
             
        vector<vector<bool>>pacific(m,vector<bool>(n,false));


        //calling it from the left and rifght borders
        for(int i=0;i<m;i++)
        {
          dfs(i,0,heights,pacific);
          dfs(i,n-1,heights,atlantic);
        }
//top and down borxers
        for(int j=0;j<n;j++)
        {
            dfs(0,j,heights,pacific);
            dfs(m-1,j,heights,atlantic);
        }
        vector<vector<int>> result;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i,j});
                }
            }
        }
return result;

        
    }
};