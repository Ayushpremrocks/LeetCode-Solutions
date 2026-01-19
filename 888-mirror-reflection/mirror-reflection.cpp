class Solution {
private:
    int calgcd(int a,int b){
        if(a%b==0) return b;
        return calgcd(b,a%b);
    }
public:
    int mirrorReflection(int p, int q) {
        int gcdd=calgcd(p,q);
        int lcmm = (p*q)/gcdd;
        int m = lcmm/p;
        int n=lcmm/q;
        if(m%2==0 && n&2!=0) return 0;
        else if(m%2!=0 && n%2!=0) return 1;
        else return 2;
    }
};