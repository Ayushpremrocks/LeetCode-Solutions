class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int ts=0;
        for(auto it:nums) ts+=it;
        vector<int>ps(n);
        ps[0]=nums[0];
        for(int i=1;i<n;i++) ps[i]+=ps[i-1];
        for(int i=0;i<n-1;i++){
            int left = ps[i];
            int right = ts-left;
            if((left-right)%2==0) count++;
        }
        return count;
    }
};