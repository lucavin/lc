/*
 * @lc app=leetcode id=485 lang=c
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
int get_surrounding(int *nums, int numsSize, int index) {
  int count = 0;

  // count post
  for (int i = index + 1; i < numsSize && nums[i] != 0; i++) {
    count++;
  }
  // count pre
  for (int i = index - 1; i >= 0 && nums[i] != 0; i--) {
    count++;
  }

  return count + 1;
}

int findMaxConsecutiveOnes(int *nums, int numsSize) {
  if (numsSize == 1) {
    return 1;
  }

  int max = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 0) {
      int surr_i = get_surrounding(nums, numsSize, i);
      if (surr_i > max) {
        max = surr_i;
      }
    }
  }

  if (max == 0) {
    return numsSize;
  }

  return max;
}
// @lc code=end
