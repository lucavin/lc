/*
 * @lc app=leetcode id=1089 lang=c
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
void duplicateZeros(int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] == 0) {
      for (int j = arrSize - 1; j > i; j--) {
        arr[j] = arr[j - 1];
      }
      i++;
    }
  }
}
// @lc code=end
