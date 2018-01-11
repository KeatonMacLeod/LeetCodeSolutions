class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int r=0; r < board.size(); r++)
            for (int c=0; c < board[0].size(); c++) {
                if (board[r][c] == 'X' && ((r == board.size()-1 || board[r+1][c] != 'X') &&
                                           (c == board[0].size()-1 || board[r][c+1] != 'X')))
                count++;
            }
    return count;
    }
};
