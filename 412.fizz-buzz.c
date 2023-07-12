/*
 * @lc app=leetcode id=412 lang=c
 *
 * [412] Fizz Buzz
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize) {
  *returnSize = 0;

  char **ans = malloc(n * sizeof(char *));

  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      char *str = malloc(9 * sizeof(char));
      strcpy(str, "FizzBuzz");
      ans[i - 1] = str;
    } else if (i % 3 == 0) {
      char *str = malloc(5 * sizeof(char));
      strcpy(str, "Fizz");
      ans[i - 1] = str;
    } else if (i % 5 == 0) {
      char *str = malloc(5 * sizeof(char));
      strcpy(str, "Buzz");
      ans[i - 1] = str;
    } else {
      char cpy[6];
      sprintf(cpy, "%d", i);
      int j = 0;
      for (j; cpy[j] != '\0'; j++)
        ;
      char *str = malloc((j + 1) * sizeof(char));
      strcpy(str, cpy);
      ans[i - 1] = str;
    }
    (*returnSize)++;
  }
  return ans;
}
// @lc code=end
