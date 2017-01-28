#include <vector>
#include <iostream>
using namespace std;

// LC33: Search in Rotated Array
// Suppose an array sorted in ascending order is rotated at some
// pivot unknown to you before hand.
// i.e. 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2
// You are given a target value to search. If found in the array
// return its index, otherwise return -1
// You may assume no duplicate exists in the array
// Algorithm Keywords: Array, Binary Search
int search(std::vector<int>& nums, int target) {
    if (0 == nums.size()) return -1;

    int i = 0;
    int j = nums.size() - 1;

    // Find the smallest element in array
    // using binary search
    while (i < j) {
        int mid = (i + j) / 2;
        // breaking the ascending pattern
        // The min value is on the right hand side
        if (nums[mid] > nums[j]) i = mid + 1;
        else j = mid;
    }

    // Determine the searching index boundaries
    int hi, lo;
    if (target >= nums[0]) {
        // The target is in the left half of the
        // ascending pattern
        lo = 0;
        hi = (j - 1 + nums.size()) % nums.size();
    } else {
        // The target is in the right half of the 
        // ascending pattern
        lo = j;
        hi = nums.size() - 1;
    }
    // Binary Search on the target
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (nums[mid] < target) lo = mid + 1;
        else if (nums[mid] > target) hi = mid;
        else return mid;
    }

    return nums[hi] == target ? hi : -1;
}
