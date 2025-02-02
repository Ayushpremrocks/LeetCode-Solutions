class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        if (nums.size()<0) return 0;
        int maximum = abs(nums[0]-nums[nums.size()-1]);
        for(int i=0;i<nums.size()-1;i++){
            if(abs(nums[i]-nums[i+1])>maximum){
                maximum = abs(nums[i]-nums[i+1]);
            }
        }
        return maximum;
    }
};