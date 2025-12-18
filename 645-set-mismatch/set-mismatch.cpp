// using maths
// suitable sum = n*(n+1)/2

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int ss=(n*(n+1))/2;
        int as=0;
        for(int i=0;i<n;i++) as+=nums[i];
        unordered_map<int,int>mpp;
        for(auto it:nums) mpp[it]++;
        int dup=0;
        for(auto it:mpp) if(it.second>1)dup=it.first;
        return {dup,(ss-(as-dup))};
    }
};


// using arrays and frequencies


// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>freq(n+1,0);
//         vector<int>res;
//         for(int i=0;i<n;i++) freq[nums[i]]++;
//         for(int i=1;i<n+1;i++){
//             if(freq[i]>1) res.push_back(i);
//         }
//         for(int i=1;i<n+1;i++){
//             if(freq[i]==0) res.push_back(i);
//         }
//         return res;
//     }
// };