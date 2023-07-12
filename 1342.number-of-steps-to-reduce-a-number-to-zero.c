/*
 * @lc app=leetcode id=1342 lang=c
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
int numberOfSteps(int num) {
  int steps = 0;

  while (num != 0) {
    if (num % 2 == 1) {
      num -= 1;
    } else {
      num /= 2;
    }
    steps++;
  }
  return steps;
}
// @lc code=end
