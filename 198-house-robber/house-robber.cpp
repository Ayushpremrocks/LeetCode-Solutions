class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};

// memoization

// class Solution {
// private:
//     int solve(vector<int>& nums, vector<int>& dp, int idx){
//         if(idx<0) return 0;
//         if(idx==0) return nums[0];
//         if(dp[idx]!=-1) return dp[idx];
//         return dp[idx] = max(nums[idx] + solve(nums,dp,idx-2),solve(nums,dp,idx-1));
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n,-1);
//         return solve(nums,dp,n-1);

//     }
// };