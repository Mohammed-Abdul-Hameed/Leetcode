/*
Link - https:// leetcode.com/problems/palindrome-number/
*/

#include <limits.h>  // For INT_MAX and INT_MIN

class Solution {
 public:
  bool isPalindrome(int x) {
    // Negative numbers are not palindromes
    if (x < 0) {
      return false;
    }

    int reverseNumber = 0;
    int duplicateofN = x;

    while (x > 0) {
      int lastDigit = x % 10;

      // Check if multiplying reverseNumber by 10 will cause overflow
      if (reverseNumber > (INT_MAX / 10) ||
          (reverseNumber == (INT_MAX / 10) && lastDigit > 7)) {
        return false;  // It would overflow, so return false (not a palindrome)
      }

      reverseNumber = (reverseNumber * 10) + lastDigit;
      x /= 10;
    }

    // Check if the original number is equal to the reversed number
    return duplicateofN == reverseNumber;
  }
};
