class Solution {
  private:
    int solve(int w, vector<int>& val, vector<int>& wt,vector<vector<int>>& dp, int n){
        if(w==0||n==0) return 0;
        if(dp[n][w]!=-1) return dp[n][w];
        if(wt[n-1]<=w) return dp[n][w] =max((val[n-1]+solve(w-wt[n-1],val,wt,dp,n-1)),(solve(w,val,wt,dp,n-1)));
        return dp[n][w] = solve(w,val,wt,dp,n-1);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solve(W,val,wt,dp,n);
    }
};

// recursion (tle)

// class Solution {
//   private:
//     int solve(int w, vector<int>& val, vector<int>& wt, int n){
//         if(w==0||n==0) return 0;
//         if(wt[n-1]<=w) return max((val[n-1]+solve(w-wt[n-1],val,wt,n-1)),(solve(w,val,wt,n-1)));
//         return solve(w,val,wt,n-1);
//     }
//   public:
//     int knapsack(int W, vector<int> &val, vector<int> &wt) {
//         // code here
//         int n=val.size();
//         return solve(W,val,wt,n);
//     }
// };