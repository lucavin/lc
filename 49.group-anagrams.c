/*
 * @lc app=leetcode id=49 lang=c
 *
 * [49] Group Anagrams
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include <stdbool.h>
#include <string.h>

int isAnagram(char *s, char *t) {
  int s_len = strlen(s);
  int t_len = strlen(t);

  if (s_len != t_len) {
    return false;
  }

  int s_set[26] = {0};
  int t_set[26] = {0};

  for (int i = 0; i < s_len; i++) {
    s_set[s[i] - 'a'] += 1;
    t_set[t[i] - 'a'] += 1;
  }

  for (int i = 0; i < s_len; i++) {
    if (s_set[s[i] - 'a'] != t_set[s[i] - 'a']) {
      return false;
    }
  }

  return true;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize,
                      int **returnColumnSizes) {
  char ***result = malloc(strsSize * sizeof(char **));
  *returnColumnSizes = malloc(strsSize * sizeof(int));
  *returnSize = 0;

  if (strsSize == 1) {
    result[0] = malloc(sizeof(char *));
    result[0][0] = strdup(strs[0]);
    *returnSize += 1;
    returnColumnSizes[0] = malloc(sizeof(int));
    returnColumnSizes[0][0] = 1;
    return result;
  }

  int anagram_found[10000] = {0};

  for (int i = 0; i < strsSize; i++) {
    if (anagram_found[i] != 0) {
      continue;
    }
    bool iHasAnagrams = false;
    for (int j = i + 1; j < strsSize; j++) {
      if (isAnagram(strs[i], strs[j]) && !anagram_found[j]) {
        if (iHasAnagrams == false) {
          iHasAnagrams = true;
          result[*returnSize] = malloc(strsSize * sizeof(char *));
          result[*returnSize][0] = strdup(strs[i]);
          result[*returnSize][1] = strdup(strs[j]);
          returnColumnSizes[0][*returnSize] = 2;
          *returnSize += 1;
          anagram_found[i] += 1;
          anagram_found[j] += 1;
        } else {
          result[*returnSize - 1][returnColumnSizes[0][*returnSize - 1]] =
              strdup(strs[j]);
          returnColumnSizes[0][*returnSize - 1] += 1;
          anagram_found[j] += 1;
        }
      }
    }
    if (!iHasAnagrams) {
      result[*returnSize] = malloc(strsSize * sizeof(char *));
      result[*returnSize][0] = strdup(strs[i]);
      returnColumnSizes[0][*returnSize] = 1;
      *returnSize += 1;
    }
  }

  return result;
}

// @lc code=end
