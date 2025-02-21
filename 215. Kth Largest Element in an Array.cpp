class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            int index = -1;
            sort(nums.begin(),nums.end());
            return nums[nums.size() - k];
        }
    };