class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>a(n);
        for(int i=0;i<n;i++){
            a[i]=start+2*i;
        }
        int xorr=0;
        for(auto it:a) xorr^=it;
        return xorr; 
    }
};