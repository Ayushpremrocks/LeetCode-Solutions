class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int sum=0,count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.find(sum-goal)!=mpp.end()) count+=mpp[sum-goal];
            mpp[sum]++;
        }
        return count;
    }
};