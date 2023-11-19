/*
 * @lc app=leetcode id=1657 lang=c
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
int cmp(int *a, int *b) { return *b - *a; }

bool closeStrings(char *word1, char *word2) {
  int w1 = 0;
  int w2 = 0;

  while (word1[w1] != '\0') {
    w1++;
  }
  while (word2[w2] != '\0') {
    w2++;
  }

  if (w1 != w2) {
    return false;
  }

  int *w1_occur = calloc(26, sizeof(int));
  int *w2_occur = calloc(26, sizeof(int));

  for (int i = 0; i < w1; i++) {
    int w1_idx = word1[i] - 'a';
    int w2_idx = word2[i] - 'a';
    w1_occur[w1_idx]++;
    w2_occur[w2_idx]++;
  }

  for (int i = 0; i < 26; i++) {
    if (w1_occur[i] > 0 && w2_occur[i] == 0) {
      return false;
    } else if (w1_occur[i] == 0 && w2_occur[i] > 0) {
      return false;
    }
  }

  qsort(w1_occur, 26, sizeof(int), cmp);
  qsort(w2_occur, 26, sizeof(int), cmp);

  for (int i = 0; i < 26; i++) {
    if (w1_occur[i] != w2_occur[i]) {
      return false;
    }
  }
  return true;
}
// @lc code=end
