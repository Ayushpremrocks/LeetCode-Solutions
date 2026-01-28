class Solution {
  private:
    int offset;
    int minSum, maxSum;

    int solve(vector<int>& arr, int k, vector<vector<int>>& dp, int idx) {
        if (idx < 0)
            return k == 0;

        if (k < minSum || k > maxSum)
            return 0;

        if (dp[idx][k + offset] != -1)
            return dp[idx][k + offset];

        int take = solve(arr, k - arr[idx], dp, idx - 1);
        int notTake = solve(arr, k, dp, idx - 1);

        return dp[idx][k + offset] = take + notTake;
    }

  public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();

        minSum = 0;
        maxSum = 0;
        for (int x : arr) {
            if (x < 0) minSum += x;
            else maxSum += x;
        }

        if (k < minSum || k > maxSum)
            return 0;

        offset = -minSum;
        int range = maxSum - minSum;

        vector<vector<int>> dp(n, vector<int>(range + 1, -1));

        return solve(arr, k, dp, n - 1);
    }
};
