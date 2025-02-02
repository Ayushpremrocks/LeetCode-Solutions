class Solution {
public:
    int tribonacci(int n) {
        vector<int> result(n+1,-1);
        return output(n,result);
    }
    int output(int n,vector<int> &result){
        if(n<2) return n;
        if(n==2) return 1;
        if(result[n]!=-1) return result[n];
        result[n]= output(n-3,result)+output(n-2,result)+output(n-1,result);
        return result[n];
    }
};