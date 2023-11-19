/*
 * @lc app=leetcode id=271 lang=cpp
 *
 * [271] Encode and Decode Strings

 */

// @lc code=start
class Codec {
public:
  // Encodes a list of strings to a single string.
  string encode(vector<string> &strs) {
    string result;
    for (int i = 0; i < strs.size(); i++) {
      result.append(strs[i].append("+@^"));
    }
    return result;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> result;
    if (!s.length()) {
      result.push_back("");
      return result;
    }

    int start = 0;
    int end = s.find("+@^");

    while (end != string::npos) {
      result.push_back(s.substr(start, end - start));
      // add length of "+@^" to skip to start of next word
      start = end + 3;
      end = s.find("+@^", start);
    }

    return result;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
// @lc code=end
