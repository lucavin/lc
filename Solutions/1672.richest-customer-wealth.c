/*
 * @lc app=leetcode id=1672 lang=c
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
int maximumWealth(int **accounts, int accountsSize, int *accountsColSize) {
  int curr_max = 0;
  for (int i = 0; i < accountsSize; i++) {
    int curr_sum = 0;
    for (int j = 0; j < *accountsColSize; j++) {
      curr_sum += accounts[i][j];
    }
    if (curr_sum > curr_max) {
      curr_max = curr_sum;
    }
  }
  return curr_max;
}
// @lc code=end
