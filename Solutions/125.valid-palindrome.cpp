/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;

    while (i < s.length() && j > 0) {
      if (!isalnum(s[i])) {
        i++;
        continue;
      }
      if (!isalnum(s[j])) {
        j--;
        continue;
      }
      if (tolower(s[i]) != tolower(s[j])) {
        return false;
      } else {
        i++;
        j--;
      }
    }
    return true;
  }
};
// @lc code=end
