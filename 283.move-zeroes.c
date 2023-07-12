/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 */

// @lc code=start
void moveZeroes(int *nums, int numsSize) {
  int w = 0;
  int r = 0;

  for (r; r < numsSize; r++) {
    if (nums[r] != 0) {
      nums[w] = nums[r];
      w++;
    }
  }
  for (w; w < numsSize; w++) {
    nums[w] = 0;
  }
}
// @lc code=end
