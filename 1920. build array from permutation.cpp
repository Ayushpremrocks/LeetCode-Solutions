class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> newArray(nums.size());
        for(int i=0;i<nums.size();i++){
            newArray[i] = nums[nums[i]];
        }
        return newArray;
    }
};