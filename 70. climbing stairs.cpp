class Solution {
public:
    int climbStairs(int n) {
        vector<int> result(n+1,-1);
        return output(n,result);
    }
    int output(int n,vector<int> &result){
        if(n<4) return n;
        if(result[n]!=-1) return result[n];
        result[n]=output(n-2,result)+output(n-1,result);
        return result[n];
    }
};