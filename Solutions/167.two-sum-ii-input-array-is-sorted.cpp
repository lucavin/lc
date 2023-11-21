/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
  int get_index_bin_search(vector<int> &numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (numbers[m] > target) {
        r = m - 1;
      } else if (numbers[m] < target) {
        l = m + 1;
      } else {
        return m;
      }
    }
    return -1;
  }

  vector<int> twoSum(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
      int num_to_find = target - numbers[i];
      int num_to_find_index = get_index_bin_search(numbers, num_to_find);
      if (num_to_find_index != -1 && num_to_find_index != i) {
        return i > num_to_find_index
                   ? vector<int>{num_to_find_index + 1, i + 1}
                   : vector<int>{i + 1, num_to_find_index + 1};
      }
    }
    return vector<int>{};
  }
};
// @lc code=end
