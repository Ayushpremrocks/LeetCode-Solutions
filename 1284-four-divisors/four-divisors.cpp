class Solution {
private:
    int chkDivisors(int n){
        set<int>s;
        s.insert(1);
        s.insert(n);
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                s.insert(i);
                s.insert(n/i);
            }
        }
        int sum=0;
        if(s.size()!=4) return 0;
        for(auto it:s) sum+=it;
        return sum;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int count=0;
        for(auto it:nums){
            count+=chkDivisors(it);
        }
        return count;
    }
};