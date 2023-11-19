/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
  bool containsDupes(vector<char> str) {
    bool seen[256];
    memset(seen, false, 256);

    for (int i = 0; i < 9; i++) {
      int c = str[i];
      if (c != (int)'.' && seen[c]) {
        return true;
      }
      seen[c] = true;
    }
    return false;
  }

  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      if (containsDupes(board[i])) {
        return false;
      }
    }

    for (int j = 0; j < 9; j++) {
      vector<char> curr_col;
      for (int i = 0; i < 9; i++) {
        curr_col.push_back(board[i][j]);
      }
      if (containsDupes(curr_col)) {
        return false;
      }
    }

    for (int i = 0; i < 3; i++) {
      int curr_row = i * 3;
      for (int j = 0; j < 3; j++) {
        int curr_col = j * 3;
        vector<char> sub_box_chars;
        sub_box_chars.push_back(board[curr_row][curr_col]);
        sub_box_chars.push_back(board[curr_row][curr_col + 1]);
        sub_box_chars.push_back(board[curr_row][curr_col + 2]);
        sub_box_chars.push_back(board[curr_row + 1][curr_col]);
        sub_box_chars.push_back(board[curr_row + 1][curr_col + 1]);
        sub_box_chars.push_back(board[curr_row + 1][curr_col + 2]);
        sub_box_chars.push_back(board[curr_row + 2][curr_col]);
        sub_box_chars.push_back(board[curr_row + 2][curr_col + 1]);
        sub_box_chars.push_back(board[curr_row + 2][curr_col + 2]);
        if (containsDupes(sub_box_chars)) {
          return false;
        }
      }
    }

    return true;
  }
};
// @lc code=end
