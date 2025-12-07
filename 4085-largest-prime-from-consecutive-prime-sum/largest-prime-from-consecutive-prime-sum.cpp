class Solution {
private:
    vector<bool>chkPrime(int n){
        vector<bool>p(n+1,true);
        p[0]=p[1]=false;

        for(int i=2;i*i<=n;i++){
            if(p[i]){
                for(int j=i*i;j<=n;j+=i){
                    p[j]=false;
                }
            }
        }
        return p;
    }
public:
    int largestPrime(int n) {
        if(n<2) return 0;
        vector<bool>p=chkPrime(n);
        vector<int>res;
        for(int i=2;i<=n;i++) if(p[i]) res.push_back(i);

        int currSum=0;
        int sum=0;
        for(int i=0;i<res.size();i++){
            currSum+=res[i];
            if(currSum>n) break;
            if(p[currSum]) sum=currSum;
        }
        return sum;
    }
};