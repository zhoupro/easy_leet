/* Ugly Number
 * 
 * [Easy] [AC:40.6% 157.2K of 387.1K] [filetype:cpp]
 * 
 * Write a program to check whether a given number is an ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2,
 * 3, 5.
 * 
 * Example 1:
 * 
 * Input: 6
 * 
 * Output: true
 * 
 * Explanation: 6 = 2 × 3
 * 
 * Example 2:
 * 
 * Input: 8
 * 
 * Output: true
 * 
 * Explanation: 8 = 2 × 2 × 2
 * 
 * Example 3:
 * 
 * Input: 14
 * 
 * Output: false 
 * 
 * Explanation: 14 is not ugly since it includes another prime factor 7.
 * 
 * Note:
 * 
 * 1 is typically treated as an ugly number.
 * 
 * Input is within the 32-bit signed integer range: [−231,  231 − 1].
 * 
 * [End of Description] */
class Solution {
public:
    bool isUgly(int num) {
        int fac[3] = {2,3,5};
        while(num != 1){
            int ori_num = num;
            for(int i=0; i< 3;i++){
                if(num % fac[i] == 0){
                    num = num / fac[i];
                }
            }
            if(num == ori_num){
                return false;
            }
            return isUgly(num);
        }
        return true;
    }
};
