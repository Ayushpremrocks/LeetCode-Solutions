class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long long a=6,b=6;
        for(int i=1;i<n;i++){
            long long new_a=(a*3+b*2)%MOD;
            long long new_b=(a*2+b*2)%MOD;
            a = new_a;
            b = new_b;
        }
        return (a+b)%MOD;
    }
};