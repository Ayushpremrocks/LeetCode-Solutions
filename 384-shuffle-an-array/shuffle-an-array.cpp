class Solution {
public:
    vector<int>temp;
    vector<int>res;
    Solution(vector<int>& nums) {
        temp=nums;
        res=nums;
    }
    
    vector<int> reset() {
        return temp;
    }
    
    vector<int> shuffle() {
        next_permutation(res.begin(),res.end());
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */