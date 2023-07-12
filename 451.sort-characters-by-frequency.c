/*
 * @lc app=leetcode id=451 lang=c
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
typedef struct {
  char c;
  int freq;
} char_freq;

int cmp(const void *a, const void *b) {
  return (*(char_freq *)b).freq - (*(char_freq *)a).freq;
}

char *frequencySort(char *s) {
  char *iterator = s;
  char_freq char_set[62] = {
      {'0', 0}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0},
      {'7', 0}, {'8', 0}, {'9', 0}, {'A', 0}, {'B', 0}, {'C', 0}, {'D', 0},
      {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0}, {'K', 0},
      {'L', 0}, {'M', 0}, {'N', 0}, {'O', 0}, {'P', 0}, {'Q', 0}, {'R', 0},
      {'S', 0}, {'T', 0}, {'U', 0}, {'V', 0}, {'W', 0}, {'X', 0}, {'Y', 0},
      {'Z', 0}, {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0},
      {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0},
      {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0},
      {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};

  for (; *iterator; ++iterator) {
    if (isdigit(*iterator))
      ++char_set[*iterator - '0'].freq;
    else if (islower(*iterator))
      ++char_set[*iterator - 61]
            .freq; // Index is equivalent to *iterator - 'a' + 10 + 26
    else
      ++char_set[*iterator - 55]
            .freq; // Index is equivalent to *iterator - 'A' + 10
  }

  qsort(char_set, 62, sizeof(char_freq), cmp);

  iterator = s;
  for (int i = 0; i < 62; ++i)
    for (; char_set[i].freq; --char_set[i].freq)
      *iterator++ = char_set[i].c;

  return s;
}
// @lc code=end
