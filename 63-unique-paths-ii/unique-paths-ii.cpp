class Solution {
private:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n, int i, int j){
        if(i>=m || j>=n || grid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]= solve(grid,dp,m,n,i+1,j)+solve(grid,dp,m,n,i,j+1);
        return dp[i][j];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(obstacleGrid,dp,m,n,0,0);
    }
};