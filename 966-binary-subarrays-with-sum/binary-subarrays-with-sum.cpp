class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>ps(n);
        ps[0]=nums[0];
        int count=0;
        for(int i=1;i<n;i++) ps[i]=nums[i]+ps[i-1];
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(ps[i]==goal) count++;
            if(mpp.find(ps[i]-goal)!=mpp.end()) count+=mpp[ps[i]-goal];
            mpp[ps[i]]++;
        }
        return count;
    }
};