class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            unordered_map<int, int> freq;
            for (int c:nums) {
                freq[c]++;
            }
            for (auto& entry : freq) {
                if (entry.second == 1) {
                    return entry.first;
                }
            }
            return -1;
        }    
    };