/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
int removeDuplicates(int *nums, int numsSize) {
  int r = 1;
  int w = 0;
  int curr_num = nums[0];
  w++;

  while (r < numsSize) {
    if (nums[r] == curr_num) {
      r++;
    } else {
      nums[w] = nums[r];
      curr_num = nums[r];
      r++;
      w++;
    }
  }
  return w;
}
// @lc code=end
