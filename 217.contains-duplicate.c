/*
 * @lc app=leetcode id=217 lang=c
 *
 * [217] Contains Duplicate
 */

// @lc code=start
int compare(int *a, int *b) { return *a - *b; }

bool containsDuplicate(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  for (int i = 1; i < numsSize; i++) {
    if (nums[i - 1] == nums[i]) {
      return true;
    }
  }
  return false;
}

// @lc code=end
