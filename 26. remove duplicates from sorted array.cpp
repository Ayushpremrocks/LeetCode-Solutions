class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0,j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
            }else{
                count++;
            }
        }
        return j+1;
    }
};