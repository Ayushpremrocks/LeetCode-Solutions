class Solution {
  private:
    int solve(vector<int>& arr, vector<vector<int>>& dp, int n, int sum, int i){
        if(i==n){
            if(sum==0) return 1;
            else return 0;
        }
        if(sum<0) return 0;
        
        if(dp[i][sum]!=-1)  return dp[i][sum];
        return dp[i][sum] = (solve(arr,dp,n,sum-arr[i],i+1)+solve(arr,dp,n,sum,i+1));
    }
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int ts=0;
        for(auto it:arr) ts+=it;
        if(ts<diff) return 0;
        if((ts+diff)%2!=0) return 0;
        int sum=(ts+diff)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,dp,n,sum,0);
    }
};