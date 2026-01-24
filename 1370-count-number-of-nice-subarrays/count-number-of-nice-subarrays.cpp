class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ps(n);
        vector<int>oc(n);
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) oc[i]=0;
            else oc[i]=1;
        }
        ps[0]=oc[0];
        for(int i=1;i<n;i++) ps[i]=oc[i]+ps[i-1];
        int count=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(ps[i]==k) count++;
            if(mpp.find(ps[i]-k)!=mpp.end()) count+=mpp[ps[i]-k];
            mpp[ps[i]]++;
        }
        return count;
    }
};