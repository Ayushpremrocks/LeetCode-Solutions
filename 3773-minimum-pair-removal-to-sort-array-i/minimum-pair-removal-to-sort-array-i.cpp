class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int c=0;
        while(!is_sorted(nums.begin(),nums.end())){
            int j=0;
            int mini=nums[0]+nums[1];

            for(int i=1;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];
                if(sum<mini){
                    mini = sum;
                    j=i;
                }
            }
            c++;
            nums[j]=mini;
            nums.erase(nums.begin()+j+1);
        }
        return c;
    }
};
