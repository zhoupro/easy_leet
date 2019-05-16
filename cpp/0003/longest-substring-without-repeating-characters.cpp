/* Longest Substring Without Repeating Characters
 * 
 * [Medium] [AC:28.3% 913.3K of 3.2M] [filetype:cpp]
 * 
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Example 1:
 * 
 * Input: "abcabcbb"
 * 
 * Output: 3 
 * 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * Example 2:
 * 
 * Input: "bbbbb"
 * 
 * Output: 1
 * 
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * 
 * Input: "pwwkew"
 * 
 * Output: 3
 * 
 * Explanation: The answer is "wke", with the length of 3. 
 * 
 *              Note that the answer must be a substring, "pwke" is a
 *              subsequence and not a substring.
 * 
 * [End of Description] */
#include <string>
#include <set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int str_len =  s.size();
        int max_len = 0, most_len = 0;
        set<char>  se;
        for(int i=0;i<str_len;i++){
            se.insert(s[i]);
            max_len++; 
            for(int j=i+1; j<str_len; j++){
                if( (se.find(s[j]) != se.end()) || ((str_len - i + 1) <= most_len)){
                    break;
                }else{
                    se.insert(s[j]);
                    max_len++;
                }
            }
            if(max_len > most_len){
                most_len = max_len;
            }
            se.clear();
            max_len = 0;
        }
        return most_len;
    }
};
