#include <iostream>
#include <vector>

class Solution {
private:
  void helper(std::vector<char> &s, int left_idx, int right_idx) {
    if (left_idx >= right_idx) return;
    char tmp = s[left_idx];
    s[left_idx++] = s[right_idx];
    s[right_idx--] = tmp;
    helper(s, left_idx, right_idx);
  }

  void _reverseString01(std::vector<char> &s) {
    helper(s, 0, s.size() - 1);
  }

  void _reverseString02(std::vector<char> &s) {
    int left_idx = 0;
    int right_idx = s.size() -1;
    while (left_idx < right_idx) {
      // swap s[left_idx] and s[right_idx];
      char tmp = s[left_idx];
      s[left_idx] = s[right_idx];
      s[right_idx] = tmp;
      // move left_idx and right_idx to inner.
      left_idx++; right_idx--;
    }
  }

public:
  void reverseString(std::vector<char> &s) {
    _reverseString02(s);
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  std::vector<char> str{'h', 'e', 'l', 'l', 'o'};

  sol.reverseString(str);
  std::vector<char>::iterator itr_str = str.begin();
  while (itr_str != str.end()) {
    std::cout << "'" << *itr_str << "' ";
    itr_str++;
  }
  std::cout << std::endl;
}
