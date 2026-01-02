class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        long long xorr=0;
        for(auto it:arr) xorr^=it;
        long long rightmost = xorr & (-xorr);
        int b1=0,b2=0;
        for(auto it: arr){
            if(rightmost&it) b1^=it;
            else b2^=it;
        }
        if (b1>b2) return {b1,b2};
        else return {b2,b1};
    }
};