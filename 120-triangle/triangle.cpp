class Solution {
private:
    int solve(vector<vector<int>>& triangle, vector<vector<int>>& dp, int n, int i, int j){
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];
        return dp[i][j] = min(triangle[i][j]+solve(triangle,dp,n,i+1,j),triangle[i][j]+solve(triangle,dp,n,i+1,j+1));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        return solve(triangle,dp,n,0,0);
    }
};