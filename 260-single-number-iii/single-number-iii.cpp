class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        for(int it:nums) xorr^=it;
        long long rightmost = (xorr & (-xorr));
        int b1=0,b2=0;
        for(auto it:nums){
            if(rightmost&it) b1^=it;
            else b2^=it;
        }
        return {b1,b2};
    }
};