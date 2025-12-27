class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        if((n>>k)&1!=0) return true;
        else return false;
    }
};