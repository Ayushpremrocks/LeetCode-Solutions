class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pref[i][j] = mat[i-1][j-1] 
                           + pref[i-1][j] 
                           + pref[i][j-1] 
                           - pref[i-1][j-1];
            }
        }

        auto getsum = [&](int r,int c,int k){
            return pref[r+k][c+k] - pref[r][c+k] - pref[r+k][c] + pref[r][c];
        };

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int lo = ans + 1;
                while(i + lo <= n && j + lo <= m && getsum(i,j,lo) <= threshold){
                    ans = lo;
                    lo++;
                }
            }
        }
        return ans;
    }
};
