/*
 * @lc app=leetcode id=1704 lang=c
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
bool is_vowel(char c) {
  if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
      c == 'o' || c == 'O' || c == 'u' || c == 'U') {
    return true;
  }
  return false;
}

bool halvesAreAlike(char *s) {
  int length = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    length++;
  }

  int h1_count = 0;
  int h2_count = 0;

  for (int i = 0; i < (length / 2); i++) {
    if (is_vowel(s[i]) == true) {
      h1_count++;
    }
  }

  for (int i = (length / 2); i < length; i++) {
    if (is_vowel(s[i]) == true) {
      h2_count++;
    }
  }

  if (h1_count == h2_count) {
    return true;
  } else {
    return false;
  }
}
// @lc code=end
