class Solution {
    const long long MOD = 1e9+7;
    long long power(long long x,long long y){
        if (y==0) return 1;
        long long temp = power(x,y/2);
        if(y%2==0){
            return (temp*temp)%MOD;
        }else{
            return (x*temp*temp)%MOD;
        }
    }
public:
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long evenPlaces = power(5,even)%MOD;
        long long oddPlaces = power(4,odd)%MOD;
        return (int)((evenPlaces*oddPlaces)%MOD);
    }
};