class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> value(2*nums.size());
        for(int i=0;i<nums.size();i++){
            value[i]=nums[i];
            value[i+nums.size()]=nums[i];
        }
        return value;
    }
};