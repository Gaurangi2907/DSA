class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                string num(1, board[i][j]);
                if (!s.insert(num + "row" + to_string(i)).second ||
                    !s.insert(num + "col" + to_string(j)).second ||
                    !s.insert(num + "box" + to_string(i / 3) + to_string(j / 3))
                         .second)
                    return false;
            }
        }
        return true;
    }
};
