/* ZigZag Conversion
 * 
 * [Medium] [AC:31.9% 320K of 1M] [filetype:cpp]
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given
 * number of rows like this: (you may want to display this pattern in a
 * fixed font for better legibility)
 * 
 * P   A   H   N
 * 
 * A P L S I I G
 * 
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * 
 * Output: "PAHNAPLSIIGYIR"
 * 
 * Example 2:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * 
 * Output: "PINALSIGYAHRPI"
 * 
 * Explanation:
 * 
 * P     I    N
 * 
 * A   L S  I G
 * 
 * Y A   H R
 * 
 * P     I
 * 
 * [End of Description] */
#include <string>
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int s_len = s.size();
        char **b = new char *[numRows];
        for(int i=0;i<numRows;i++){
            b[i] = new char[s_len];
            for(int j=0;j<s_len;j++){
                b[i][j] = -1;
            }
        }
        int tmp = 2*numRows - 2;

        for(int i=0;i<s_len;i++){
            int j = i % tmp;
            int k = i / tmp;
            int x,y;

            if(j < numRows){
                y = k*numRows;
                x= j;
            }else{
                int l = j-(numRows-1);
                y = k*numRows + l;
                x = (numRows-1) - l;
            }
            b[x][y] = s[i];
        }
        string ret;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s_len;j++){
                if(int(b[i][j]) != -1){
                    ret.push_back(b[i][j]);
                }
            }
        }
        return ret;

    }
};
