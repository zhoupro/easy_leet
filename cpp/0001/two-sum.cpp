/* Two Sum
 * 
 * [Easy] [AC:44.0% 1.8M of 4M] [filetype:cpp]
 * 
 * Given an array of integers, return indices of the two numbers such that
 * they add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you
 * may not use the same element twice.
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * 
 * return [0, 1].
 * 
 * [End of Description] */
#include <vector>
#include <set>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int total_size = nums.size();
        vector<int> ret;
        for(int i=0;i< total_size;i++){
            for(int j=i+1; j < total_size ;j++){
                if(target == nums[i] + nums[j]){
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};
