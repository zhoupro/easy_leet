/* Reverse Integer
 * 
 * [Easy] [AC:25.3% 696.5K of 2.8M] [filetype:cpp]
 * 
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * Input: 123
 * 
 * Output: 321
 * 
 * Example 2:
 * 
 * Input: -123
 * 
 * Output: -321
 * 
 * Example 3:
 * 
 * Input: 120
 * 
 * Output: 21
 * 
 * Note:
 * 
 * Assume we are dealing with an environment which could only store
 * integers within the 32-bit signed integer range: [−231,  231 − 1]. For
 * the purpose of this problem, assume that your function returns 0 when
 * the reversed integer overflows.
 * 
 * [End of Description] */
#include <climits>
class Solution {
public:
    int reverse(int x) {
        int n;
        int ret = 0;
        while(x != 0){
            n = x % 10;
            ret = ret * 10 + n;
            if(ret > INT_MAX || ret < INT_MIN){
                return 0;
            }
            x = x / 10;
        }
        return ret;
    }
};
