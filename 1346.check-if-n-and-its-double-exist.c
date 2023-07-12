/*
 * @lc app=leetcode id=1346 lang=c
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
bool checkIfExist(int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    for (int j = 0; j < arrSize; j++) {
      if (j != i && arr[j] == 2 * arr[i]) {
        return true;
      }
    }
  }
  return false;
}
// @lc code=end
