#ifndef ARR_ALG_H
#define ARR_ALG_H

// LC33: Search in Rotated Array
// Suppose an array sorted in ascending order is rotated at some
// pivot unknown to you before hand.
// i.e. 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2
// You are given a target value to search. If found in the array
// return its index, otherwise return -1
// You may assume no duplicate exists in the array
int search(std::vector<int>& nums, int target);

#endif
