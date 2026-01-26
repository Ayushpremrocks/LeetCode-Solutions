class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff=INT_MAX;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            if((arr[i+1]-arr[i])<minDiff) minDiff=min(minDiff,abs(arr[i+1]-arr[i]));
        }
        vector<vector<int>>res;
        for(int i=0;i<n-1;i++) if(abs(arr[i+1]-arr[i])==minDiff) res.push_back({arr[i],arr[i+1]});
        return res;
    }
};