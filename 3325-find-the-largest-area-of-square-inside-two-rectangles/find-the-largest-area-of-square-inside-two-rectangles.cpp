class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxi=0;
        for(long long i=0;i<bottomLeft.size();i++){
            for(long long j=i+1;j<bottomLeft.size();j++){
                long long trx = min(topRight[i][0],topRight[j][0]);
                long long blx = max(bottomLeft[i][0],bottomLeft[j][0]);
                long long w=trx-blx;

                long long tryy = min(topRight[i][1],topRight[j][1]);
                long long bly = max(bottomLeft[i][1],bottomLeft[j][1]);
                long long h=tryy-bly;

                long long side = min(w,h);
                maxi=max(maxi,side);
            }
        }
        return maxi*maxi;
    }
};