/*
 * @lc app=leetcode id=1295 lang=c
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
int findNumbers(int *nums, int numsSize) {
  int ans = 0;
  for (int i = 0; i < numsSize; i++) {
    int div_num = 0;
    while (nums[i] >= 1) {
      nums[i] /= 10;
      div_num++;
    }
    if (div_num % 2 == 0) {
      ans++;
    }
  }
  return ans;
}
// @lc code=end
