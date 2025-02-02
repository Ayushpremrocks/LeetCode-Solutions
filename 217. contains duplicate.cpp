class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        bool value = false;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                value = true;
            }
        }
        return value;
    }
};