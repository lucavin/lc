/*
 * @lc app=leetcode id=941 lang=c
 *
 * [941] Valid Mountain Array
 */

// @lc code=start

bool validMountainArray(int *arr, int arrSize) {
  if (arr == NULL || arrSize < 3) {
    return false;
  }

  int i = 0;
  while (i < arrSize - 1 && arr[i] < arr[i + 1]) {
    i++;
  }

  if (i + 1 == arrSize || i == 0) {
    return false;
  }

  while (i < arrSize - 1 && arr[i] > arr[i + 1]) {
    i++;
  }

  if (i + 1 == arrSize) {
    return true;
  } else {
    return false;
  }
}
// @lc code=end
