/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> nums_set(nums.begin(), nums.end());

    int max_set_len = 0;

    for (int num : nums) {
      int set_len = 1;
      if (nums_set.find(num - 1) == nums_set.end()) {
        for (int i = 1; nums_set.find(num + i) != nums_set.end(); i++) {
          set_len++;
        }
      }
      if (set_len >= max_set_len) {
        max_set_len = set_len;
      }
    }

    return max_set_len;
  }
};
// @lc code=end
