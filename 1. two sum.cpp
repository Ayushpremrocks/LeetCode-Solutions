class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size();i++){
            int compliment = target - nums[i];
            if(hashmap.find(compliment)!=hashmap.end()){
                return {hashmap[compliment],i};
            }
            hashmap[nums[i]]=i;
        }
        return {};
    }
};