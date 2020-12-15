#include <iostream>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    // std::size_t len_nums1 = nums1.size(), len_nums2 = nums2.size();
    std::vector<int> A, B;
    std::size_t imin, imax, half_len, m, n, max_of_left, min_of_right;
    if (nums1.size() <= nums2.size()) {
      A = nums1; B = nums2;
    } else {
      B = nums1; A = nums2;
    }
    m = A.size(); n = B.size();
    imin = 0; imax = m; half_len = (m + n + 1) / 2;

    while (imin <= imax) {
      std::size_t i, j;
      i = (imin + imax) / 2;
      j = half_len - 1;
      if ((i < m) && (B[j-1] > A[i])) {
        imin = i + 1;
      } else if (i > 0 && A[i-1] > B[j]) {
        imax = i - 1;
      } else {
        if (i == 0) { max_of_left = B[j-1]; }
        else if (j == 0) { max_of_left = A[i-1];}
        else { max_of_left = (A[i-1] > B[j-1]) ? A[i-1] : B[j-1];}

        if ((m+n) % 2 == 1) {
          min_of_right = max_of_left;
          return (double)max_of_left;
          break;
        }

        if (i == m) { min_of_right = B[j]; }
        else if (j == m) { min_of_right = A[i]; }
        else { min_of_right = (A[i] < B[j]) ? A[i] : B[j]; }

        return double(max_of_left + min_of_right) / 2.0;
      }
    }
    return 0.0;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  std::vector<int> nums1, nums2;

  int ret;
  std::string str;

  nums1 = {1, 3};
  nums2 = {2, 4};
  std::cout << sol.findMedianSortedArrays(nums1, nums2) << std::endl;
}
