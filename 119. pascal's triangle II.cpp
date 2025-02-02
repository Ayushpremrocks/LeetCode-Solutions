class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        long long ans =1;
        result.push_back(ans);
        for(int column=1;column<=rowIndex;column++){
            ans = ans*(rowIndex-column+1);
            ans = ans/column;
            result.push_back(ans);
        }
        return result;
    }
};