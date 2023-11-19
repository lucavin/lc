/*
 * @lc app=leetcode id=1207 lang=c
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

bool uniqueOccurrences(int *arr, int arrSize) {

  int myarr[2001] = {0};

  for (int i = 0; i < arrSize; i++) {
    (*(myarr + (*(arr + i) + 1000)))++;
  }
  qsort(myarr, 2001, sizeof(int), cmpfunc);
  for (int i = 2000; *(myarr + i) != 0; --i) {

    if (*(myarr + i) == *(myarr + i - 1))
      return false;
  }

  return true;
}
// @lc code=end
