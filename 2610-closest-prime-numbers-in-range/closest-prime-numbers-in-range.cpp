class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(left==right) return {-1,-1};
        int limit = sqrt(right)+1;
        vector<bool>temp(limit+1,true);
        vector<int>primes;
        for(int i=2;i<=limit;i++){
            if(temp[i]){
                primes.push_back(i);
                for(int j=i*i;j<=limit;j+=i) temp[j]=false;
            }
        }

        vector<bool>isPrimes(right-left+1,true);
        vector<int>res;
        if(left==1) isPrimes[0]=false;
        for(auto p:primes){
            int start = max(p*p,(((left+p-1)/p)*p));
            for(int j=start;j<=right;j+=p){
                isPrimes[j-left]=false;
            }
        }
        for(int i=0;i<right-left+1;i++){
            if(isPrimes[i]) res.push_back(left+i);
        }
        vector<int>ans={-1,-1};
        if(res.size()<2) return ans;
        else{
            int diff=INT_MAX;
            for(int i=0;i<res.size()-1;i++){
                if(res[i+1]-res[i]<diff){
                    diff=min(diff,res[i+1]-res[i]);
                    ans = {res[i],res[i+1]};
                }
            }
        }
        return ans;
    }
};