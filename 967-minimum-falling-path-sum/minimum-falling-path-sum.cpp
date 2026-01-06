class Solution {
private:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int m, int n, int i, int j){
        if(j<0 || j>=n) return 1e9;
        if(i==m-1) return matrix[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];
        dp[i][j] = matrix[i][j] + min(solve(matrix,dp,m,n,i+1,j),min(solve(matrix,dp,m,n,i+1,j+1),solve(matrix,dp,m,n,i+1,j-1)));
        return dp[i][j];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        int res = 1e9;
        for(int j=0;j<n;j++){
            res = min(res,solve(matrix,dp,m,n,0,j));
        }
        return res;
    }
};