/*
 * @lc app=leetcode id=1299 lang=c
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *replaceElements(int *arr, int arrSize, int *returnSize) {
  *returnSize = arrSize;
  int max = arr[arrSize - 1];

  for (int i = arrSize - 1; i >= 0; i--) {
    if (arr[i] > max) {
      max = arr[i];
    } else {
      arr[i] = max;
    }
  }

  for (int i = 0; i < arrSize - 1; i++) {
    arr[i] = arr[i + 1];
  }

  arr[arrSize - 1] = -1;

  return arr;
}
// @lc code=end
