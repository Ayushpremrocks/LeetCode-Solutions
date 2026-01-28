class Solution {
private:
    int solve(vector<int>& nums, vector<int>& dp, int idx){
        if(idx<0) return 0;
        if(idx==0) return nums[0];
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = max(nums[idx] + solve(nums,dp,idx-2),solve(nums,dp,idx-1));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,dp,n-1);

    }
};