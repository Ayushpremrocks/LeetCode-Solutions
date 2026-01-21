class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(x == 2) continue;
            for(int b = 1; b < 32; b++){
                if(((x >> b) & 1) == 0){
                    res[i] = x ^ (1 << (b - 1));
                    break;
                }
            }
        }
        return res;
    }
};
