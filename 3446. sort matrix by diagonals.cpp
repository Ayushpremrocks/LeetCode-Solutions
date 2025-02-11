class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    
            for (int i = 0; i < grid.size(); ++i) {
            vector<int> diagonal;
            int row = i, col = 0;
            while (row < grid.size() && col < grid.size()) {
                diagonal.push_back(grid[row][col]);
                row++; col++;
            }
            sort(diagonal.rbegin(), diagonal.rend());
            row = i, col = 0; int z = 0;
            while (row < grid.size() && col < grid.size()) {
                grid[row][col] = diagonal[z++];
                row++; col++;
            }
        }
        for (int j = 1; j < grid.size(); ++j) {
            vector<int> diagonal;
            int row = 0, col = j;
            while (row < grid.size() && col < grid.size()) {
                diagonal.push_back(grid[row][col]);
                row++; col++;
            }
            sort(diagonal.begin(), diagonal.end());
            row = 0, col = j; int z = 0;
            while (row < grid.size() && col < grid.size()) {
                grid[row][col] = diagonal[z++];
                row++; col++;
            }
        }
        return grid;
        }
    };