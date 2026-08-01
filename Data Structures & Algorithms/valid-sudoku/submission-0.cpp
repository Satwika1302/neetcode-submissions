class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r=0;r<9;r++){
            unordered_set<char> s;
            for(int i=0;i<9;i++){
                if(board[r][i]=='.')continue;
                if(s.count(board[r][i])){
                    return false;
                }
                s.insert(board[r][i]);
            }
        }

        for(int c=0;c<9;c++){
            unordered_set<char> s;
            for(int i=0;i<9;i++){
                if(board[i][c]=='.')continue;
                if(s.count(board[i][c])){
                    return false;
                }
                s.insert(board[i][c]);
            }
        }

        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
       return true;
    }
};
