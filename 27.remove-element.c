/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start
int removeElement(int *nums, int numsSize, int val) {
  int r = 0;
  int w = 0;

  while (r < numsSize) {
    if (nums[r] != val) {
      nums[w] = nums[r];
      r++;
      w++;
    } else {
      r++;
    }
  }
  return w;
}
// @lc code=end
