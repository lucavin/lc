/*
 * @lc app=leetcode id=347 lang=c
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct number {
  int number;
  int occurences;
};

int cmp(const void *aa, const void *bb) {
  struct number *a = (struct number *)aa;
  struct number *b = (struct number *)bb;

  return b->occurences - a->occurences;
}

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize) {
  *returnSize = numsSize < k ? numsSize : k;
  int *result = malloc(*returnSize * sizeof(int));

  struct number numberMap[20000] = {0, 0};

  for (int i = 0; i < numsSize; i++) {
    numberMap[nums[i] + 10000].number = nums[i];
    numberMap[nums[i] + 10000].occurences++;
  }

  qsort(numberMap, 20000, sizeof(struct number), cmp);

  for (int i = 0; i < *returnSize; i++) {
    result[i] = numberMap[i].number;
  }

  return result;
}
// @lc code=end
