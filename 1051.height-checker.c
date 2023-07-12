/*
 * @lc app=leetcode id=1051 lang=c
 *
 * [1051] Height Checker
 */

// @lc code=start
int compare(int *a, int *b) { return *a - *b; }

int heightChecker(int *heights, int heightsSize) {
  int ordered[heightsSize];

  for (int i = 0; i < heightsSize; i++) {
    ordered[i] = heights[i];
  }

  qsort(ordered, heightsSize, sizeof(int), compare);

  int counter = 0;

  for (int i = 0; i < heightsSize; i++) {
    if (ordered[i] != heights[i]) {
      counter++;
    }
  }

  return counter;
}
// @lc code=end
