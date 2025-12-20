class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mpp;
        long long count=0;
        mpp[0]=1;
        int xr=0;
        for(int i=0;i<arr.size();i++){
            xr^=arr[i];
            int x=xr^k;
            count+=mpp[x];
            mpp[xr]++;
        }
        return count;
    }
};