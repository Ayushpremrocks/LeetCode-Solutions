class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        vector<pair<int,int>>cells;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cells.push_back({i,j});
            }
        }

        sort(cells.begin(),cells.end(),
            [&](auto a,auto b){
            return grid[a.first][a.second]<grid[b.first][b.second];
        });

        for(int i=0;i<=k;i++){
            int bestCase=INT_MAX;
            for(int j=0;j<cells.size();j++){
                int x = cells[j].first;
                int y= cells[j].second;

                bestCase = min(bestCase,dp[x][y]);

                if(j+1<cells.size() && grid[x][y]==grid[cells[j+1].first][cells[j+1].second]) continue;

                int back=j;
                while(back>=0 && grid[cells[back].first][cells[back].second]==grid[x][y]){
                    dp[cells[back].first][cells[back].second]=bestCase;
                    back--;
                }
            }

            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    if(i==n-1 && j==m-1){
                        dp[i][j]=0;
                    }

                    if(i+1<n) dp[i][j] = min(dp[i][j],dp[i+1][j]+grid[i+1][j]);
                    if(j+1<m) dp[i][j] = min(dp[i][j],dp[i][j+1]+grid[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};