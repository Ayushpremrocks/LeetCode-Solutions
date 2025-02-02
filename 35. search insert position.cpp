class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int value;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                value = i;
            }else if(nums[i]<target){
                value=i+1;
            }else if(target<nums[0]){
                value=0;
            }
        }
        return value;
    }
};