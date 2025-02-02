class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                result.push_back(i);
            }
        }
        if(result.empty()){
            result = {-1,-1};
        }else if(result.size()==1){
            result.push_back(result[0]);
        }else if(result.size()>2){
            result = {result[0],result[result.size()-1]};
        }
        return result;
    }
};