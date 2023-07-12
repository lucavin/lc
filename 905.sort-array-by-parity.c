/*
 * @lc app=leetcode id=905 lang=c
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int *sortArrayByParity(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int i = 0;
  int j = numsSize - 1;

  while (i < j) {
    if (nums[i] % 2 > nums[j] % 2) {
      swap(&nums[i], &nums[j]);
    }

    if (nums[i] % 2 == 0) {
      i++;
    }
    if (nums[j] % 2 == 1) {
      j--;
    }
  }

  return nums;
}
// @lc code=end
