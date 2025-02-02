class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;
        int value_add,value_sub;
        for(int i=0;i<nums.size();i++){
            value_add=nums[i]+1;
            if(value_add%3==0){
                count++;
            }
            value_sub=nums[i]-1;
            if(value_sub%3==0){
                count++;
            }
        }
        return count;
    }
};