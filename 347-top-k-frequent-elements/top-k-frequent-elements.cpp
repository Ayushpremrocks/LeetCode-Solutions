class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<int>a;
        for(auto it:mpp){
            a.push_back(it.first);
        }
        sort(a.begin(),a.end(), [&](int a, int b) {
            return mpp[a]>mpp[b];
        });
        return vector<int>(a.begin(),a.begin()+k);
    }
};