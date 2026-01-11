class Solution {
private:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int n, int sum, int i){
        if(i==n){
            if(sum==0) return 1;
            else return 0;
        }
        if(sum<0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum] = solve(nums,dp,n,sum-nums[i],i+1) + solve(nums,dp,n,sum,i+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int ts=0;
        for(auto it:nums) ts+=it;
        if (abs(target)>ts) return 0;
        if((target+ts)%2!=0) return 0;
        int sum = (target+ts)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(nums,dp,n,sum,0);
    }
};