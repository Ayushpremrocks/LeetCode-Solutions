class Solution {
private:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n, int i ,int j){
        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=grid[i][j]+min(solve(grid,dp,m,n,i+1,j),solve(grid,dp,m,n,i,j+1));
        return dp[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,dp,m,n,0,0);
    }
};