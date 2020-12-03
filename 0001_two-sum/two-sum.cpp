#include <iostream>

class Solution {
public:
  vector<int> _brute_force_twoSum(vector<int>& nums, int target) {
    for (std::vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr) {
      for (std::vector<int>::iterator r_itr = (itr + 1); r_itr != nums.end(); ++r_itr) {
        if (target == (*r_itr + *itr)) {
          int l_idx = (int)std::distance(nums.begin(), itr);
          int r_idx = (int)std::distance(nums.begin(), r_itr);
          return vector<int> {l_idx, r_idx};
        }
      }
    }

    throw std::invalid_argument("No two sum solution");
  }

  vector<int> _two_pass_hash_table_twoSum(vector<int>& nums, int target) {
    std::map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      map.insert(std::make_pair(nums[i], i));
    }

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      decltype(map)::iterator m_itr = map.find(complement);
      if (m_itr != map.end() && i != m_itr->second) {
        int l_idx = i;
        int r_idx = m_itr->second;
        return vector<int> {l_idx, r_idx};
      }
    }
    throw std::invalid_argument("No two sum solution");
  }

  vector<int> _one_pass_hash_table_twoSum(vector<int>& nums, int target) {
    std::map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      decltype(map)::iterator m_itr = map.find(complement);
      if (m_itr != map.end()) {
        if (i < m_itr->second) {
          return vector<int> {i, m_itr->second};
        } else {
          return vector<int> {m_itr->second, i};
        }
      }
      map.insert(std::make_pair(nums[i], i));
    }
    throw std::invalid_argument("No two sum solution");
  }


  vector<int> twoSum(vector<int>& nums, int target) {
    // return _brute_force_twoSum(nums, target);
    // return _two_pass_hash_table_twoSum(nums, target);
    return _one_pass_hash_table_twoSum(nums, target);
  }

};


int main() {
  string line;
  while (std::getline(cin, line)) {
    std::vector
  }
}

