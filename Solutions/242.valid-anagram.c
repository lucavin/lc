/*
 * @lc app=leetcode id=242 lang=c
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <string.h>

bool isAnagram(char *s, char *t) {
  int s_len = strlen(s);
  int t_len = strlen(t);

  int s_set[26] = {0};
  int t_set[26] = {0};

  if (s_len != t_len) {
    return false;
  }

  for (int i = 0; i < s_len; i++) {
    s_set[s[i] - 'a']++;
    t_set[t[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (s_set[i] != t_set[i]) {
      return false;
    }
  }
  return true;
}
// @lc code=end
