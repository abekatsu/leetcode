#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:

  int _lengthOfLongestSubstring_brute_force(std::string s) {
    std::size_t strlen = s.length();
    int ret = 0;
    for (std::size_t i = 0; i < strlen; i++) {
      for (std::size_t j = i + 1; j <= strlen; j++) {
        if (allUnique(s, i, j)) {
          ret = (ret < (j - i)) ? (j - i) : ret;
        }
      }
    }
    return ret;
  }

  int _lengthOfLongestSubstring_sliding_window(std::string s) {
    std::size_t strlen = s.length();
    std::size_t i = 0, j = 0;
    std::string longest_substr;
    while (i < strlen && j < strlen) {
      std::string tmp(s, i, j - i);
      std::cout << "(i, j) = (" << i << ", " << j << "), longest_substr: " << longest_substr << ", tmp: " << tmp << std::endl;
      if (tmp.find(s[j]) == std::string::npos) {
        j++; // extend right element.
      } else {
        // find duplicate then eliminate left element.
        i++; // eliminate left element.
      }
      std::cout << "longest_substr.length(): " << longest_substr.length() << ", tmp.length(): " << tmp.length() <<  std::endl;
      if (longest_substr.length() < tmp.length()) {
        longest_substr = tmp;
      }
    }
    std::cout << longest_substr << std::endl;
    return longest_substr.length();
  }

  int _lengthOfLongestSubstring_sliding_window_optimize(std::string s) {
    std::size_t strlen = s.length();
    std::size_t i, j;
    std::unordered_map<char, std::size_t> map;
    std::string longest_substr;

    for (i = 0, j = 0; j < strlen; j++) {
      for(auto itr = map.begin(); itr != map.end(); ++itr) {
        std::cout << "key: " << itr->first << ", value: " << itr->second << std::endl;
      }

      auto it = map.find(s[j]);
      if (it != map.end()) {
        i = (map.at(s[j]) > i) ? map.at(s[j]) : i;
      }
      map[s[j]] = j + 1;

      std::cout << "longest_substr: " << longest_substr << ", candidate: " << s.substr(i, j - i + 1) <<
        ", (i, j): (" << i << ", " << j << ")" << std::endl;
      if (longest_substr.length() < (j - i + 1)) {
        longest_substr = s.substr(i, j - i + 1);
      }

    }
    return longest_substr.length();
  }

  int __lengthOfLongestSubstring(string s) {
    std::string longest_substr;
    std::size_t l_pos, r_pos, str_size;
    decltype(s)::const_iterator s_itr1, s_itr2;

    str_size = s.size();
    for (l_pos = 0; l_pos < str_size; l_pos++) {
      std::string tmp(s, l_pos, 1);
      for (r_pos = l_pos + 1; r_pos < str_size; r_pos++) {
        std::cout << "longest_substr: " << longest_substr << ", tmp: " << tmp << std::endl;
        if (tmp.find(s.at(r_pos))) {
          if (longest_substr.length() < tmp.length()) {
            longest_substr = tmp;
          }
          break;
        }
        tmp += std::string(s, r_pos, 1);
      }
    }

    return (int)longest_substr.length();
  }

  int lengthOfLongestSubstring(string s) {
    // return _lengthOfLongestSubstring_brute_force(s);
    // return _lengthOfLongestSubstring_sliding_window(s);
    return _lengthOfLongestSubstring_sliding_window_optimize(s);
  }

private:
  bool allUnique(std::string s, std::size_t start, std::size_t end) {
    std::unordered_set<char> set;
    for (std::size_t i = start; i < end; i++) {
      char &c = s[i];
      if (set.find(c) != set.end()) return false;
      set.insert(c);
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  int ret;
  std::string str;

  // str = "abcbcbb";
  // ret = sol.lengthOfLongestSubstring(str);
  // cout << "\"" << str << "\"" << ", longest substring length: " << ret << endl;
  str = "abcdeafbdgcbb";
  ret = sol.lengthOfLongestSubstring(str);
  cout << "\"" << str << "\"" << ", longest substring length: " << ret << endl;
}
