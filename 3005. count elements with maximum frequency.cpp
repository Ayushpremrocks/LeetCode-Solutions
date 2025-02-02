class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int maxFreq=0; int sum=0;
        for(auto it: freq){
            if(maxFreq<it.second){
                maxFreq = it.second;
                sum = it.second;
            }else if(maxFreq==it.second){
                sum = sum + it.second;
            }
        }
        return sum;
    }
};