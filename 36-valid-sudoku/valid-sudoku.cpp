class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>rows(9),coln(9),box(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c=='.') continue;
                int b=(i/3)*3+(j/3);
                if(rows[i].count(c) || coln[j].count(c) || box[b].count(c)) return false;
                rows[i].insert(c);
                coln[j].insert(c);
                box[b].insert(c);
            }
        }
        return true;
    }
};