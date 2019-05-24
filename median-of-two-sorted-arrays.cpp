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
            mid = (findTopK(nums1, nums2, topK) + findTopK(nums1, nums2, topK+1) ) / 2;
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
        int mid = (topK+1) / 2;
        int nums1mid = nums1.size() >= mid ? mid: nums1.size();
        int nums2mid = nums2.size() >= mid ? mid: nums2.size();

        if(nums1[nums1mid -1] < nums2[nums2mid-1] ){
            nums1 = std::vector<int>(nums1.begin()+nums1mid , nums1.end());
            mid = nums1mid;
        }else{
            nums2 = std::vector<int>(nums2.begin()+nums2mid , nums2.end());
            mid = nums2mid;
        }
        
        topK -= mid;
        return findTopK(nums1, nums2, topK);
    }
    bool isOdd(int num){
        if(1 == num % 2){
            return true;
        }
        return false;
    }
};
