class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int rows=1;rows<=numRows;rows++){
            int ans=1;
            vector<int> temp;
            temp.push_back(1);
            for(int column=1;column<rows;column++){
                ans = ans*(rows-column);
                ans = ans/column;
                temp.push_back(ans);
            }
            result.push_back(temp);
        }
        return result;
    }
};