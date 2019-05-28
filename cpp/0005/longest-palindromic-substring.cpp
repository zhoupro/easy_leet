/* Longest Palindromic Substring
 * 
 * [Medium] [AC:27.3% 556.8K of 2M] [filetype:cpp]
 * 
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * Example 2:
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * [End of Description] */
#include <string>
class Solution {
public:
    string longestPalindrome(string s) {
        int n_begin , n_end;
        int n_max;
        n_begin = 0;
        n_end = 0;
        n_max = 0;
        int i,j;
        if(s.size() == 0){
            return "";
        }
        for(i=0;i<s.size();i++){
            for( j=s.size();j>=i;j--){
                if(j-i+1 <= n_max){
                    continue;
                }
                int l = i;
                int h = j;
                while(l <= h){
                    if(s[l] != s[h]){
                        break;
                    }
                    l++;
                    h--;
                }
                if(j -i +1  > n_max && l > h){
                    n_max= j - i + 1;
                    n_begin = i;
                    n_end = j;
                }
            }
        }
        if(n_max > 0){
            return s.substr(n_begin,n_end-n_begin+1 );
        }
        return "";
    }
};
