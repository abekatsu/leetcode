#include <climits>
#include <iostream>

class Solution {
public:
  int reverse(int x) {
    int ret = 0;
    int i = 0;
    int temp = x;
    while (temp != 0) {
      // check overflows
      if ( ret > INT_MAX / 10 || ( (ret == INT_MAX / 10) && (temp % 10 > INT_MAX % 10))) {
        return 0;
      } else if ( ret < INT_MIN / 10 || ( ret == INT_MAX / 10 && temp % 10 < INT_MIN % 10 )) {
        return 0;
      }

      ret = (ret * 10) + (temp % 10);
      temp = temp / 10;
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  std::string str;

  std::cin >> str;
  std::cout << sol.reverse(std::stoi(str)) << std::endl;
}

