class Solution {
    int n, m;
    vector<vector<int>> dp;
    vector<int> a, b;

    int solve(int i, int j) {
        if (i == n || j == m) return -1e9;
        if (dp[i][j] != -1e9) return dp[i][j];

        int take = a[i] * b[j] + max(0, solve(i + 1, j + 1));
        int skip1 = solve(i + 1, j);
        int skip2 = solve(i, j + 1);

        return dp[i][j] = max({take, skip1, skip2});
    }

public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        n = a.size();
        m = b.size();
        dp.assign(n, vector<int>(m, -1e9));
        return solve(0, 0);
    }
};
