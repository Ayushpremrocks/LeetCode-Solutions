class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int largest = nums[0];
            int index = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>largest){
                    largest = nums[i];
                    index = i;
                }
            }
            return index;
        }
    };