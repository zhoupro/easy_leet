/* Median of Two Sorted Arrays
 * 
 * [Hard] [AC:26.3% 433.6K of 1.6M] [filetype:cpp]
 * 
 * There are two sorted arrays nums1 and nums2 of size m and n
 * respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time
 * complexity should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * 
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * 
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * [End of Description] */
#include <vector>
#include <iostream>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int two_array_len = nums1.size() + nums2.size();
        double mid = 0.0;
        if(isOdd(two_array_len)){
            int topK = (two_array_len + 1) / 2;
            mid = findTopK(nums1, nums2, topK);
        }else{
            int topK = (two_array_len+1) / 2;
            int topKNum = findTopK(nums1, nums2, topK);
            int topKNextNum = findTopK(nums1, nums2, topK+1);
            return (topKNum + topKNextNum) / 2.0;

        }
        return mid;
    }
    int findTopK(vector<int> nums1, vector<int> nums2, int topK){
        // break condition start
        if(0 == nums1.size()){
            return nums2[topK-1];
        }
        if(0 == nums2.size()){
            return nums1[topK-1];
        }
        if( 1 == topK ){
            if(nums1.size() > 0 && nums2.size() > 0 ){
                return nums1[0] > nums2[0] ? nums2[0] : nums1[0];
            }else if(nums1.size() > 0){
                return nums1[0];
            }else if(nums2.size() > 0){
                return nums2[0];
            }
        }
        // break condition end
        int max_de_num = topK / 2;
        if(nums1.size()< max_de_num){
            max_de_num = nums1.size();
        }
        if(nums2.size() < max_de_num){
            max_de_num = nums2.size();
        }
 if(nums1[max_de_num -1] < nums2[max_de_num - 1] ){
            nums1 = std::vector<int>(nums1.begin()+max_de_num , nums1.end());
        }else{
            nums2 = std::vector<int>(nums2.begin()+max_de_num , nums2.end());
        }
        topK = topK - max_de_num ;
        return findTopK(nums1, nums2, topK);
    }
    bool isOdd(int num){
        if(1 == num % 2){
            return true;
        }
        return false;
    }
};
