/*
 * @lc app=leetcode id=977 lang=c
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

int *sortedSquares(int *nums, int numsSize, int *returnSize) {
  int *ans = malloc(numsSize * sizeof(int));

  *returnSize = numsSize;

  for (int i = 0; i < numsSize; i++) {
    ans[i] = nums[i] * nums[i];
  }

  int i, j, min;

  for (int i = 0; i < numsSize; i++) {
    min = ans[i];
    int min_idx = i;
    for (j = i; j < numsSize; j++) {
      if (ans[j] < min) {
        min = ans[j];
        min_idx = j;
      }
    }
    swap(&ans[i], &ans[min_idx]);
  }

  return ans;
}
// @lc code=end
