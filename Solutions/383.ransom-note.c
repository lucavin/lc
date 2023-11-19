/*
 * @lc app=leetcode id=383 lang=c
 *
 * [383] Ransom Note
 */

// @lc code=start
bool canConstruct(char *ransomNote, char *magazine) {
  int *ran_arr = calloc(26, sizeof(int));
  int *mag_arr = calloc(26, sizeof(int));

  for (int i = 0; ransomNote[i] != '\0'; i++) {
    int index = ransomNote[i];
    index -= 97;
    ran_arr[index]++;
  }

  for (int i = 0; magazine[i] != '\0'; i++) {
    char test = magazine[i];
    int index = magazine[i];
    index -= 97;
    mag_arr[index]++;
  }

  for (int i = 0; ransomNote[i] != '\0'; i++) {
    int index = ransomNote[i];
    index -= 97;
    if (mag_arr[index] < ran_arr[index]) {
      free(mag_arr);
      free(ran_arr);
      return false;
    }
  }
  free(mag_arr);
  free(ran_arr);
  return true;
}
// @lc code=end
