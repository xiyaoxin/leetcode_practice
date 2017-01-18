#ifndef SUM_ALG_H
#define SUM_ALG_H

// 454 4Sum II
// Give four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
// Take make problem a bit easier, all A, B, C, D have same length of N where 0 <= N <= 500. All integers are in the range of -2^28 to 2^28-1 and the result is guaranteed to be at most 2^31 - 1
int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D); 

// 18 4Sum
// Given an array S of n integers, are there elements a, b, c and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target
// The solution set must not contain duplicate quadruplets
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target); 

// 15 3Sum
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero
std::vector<std::vector<int>> threeSum(std::vector<int>& nums); 

// 16 3Sum Closest Given an array S of n integers, find three integers in  such
// that the sum is closest to a given number, target. Return the sum of the
// three integers. You may assume that each input would have exactly one
// solution
int threeSumClosest(std::vector<int>& nums, int target);

// 259. 3Sum smaller
// Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that 
// satisfy the condition nums[i] + nums[j] + nums[k] < target
// For example, given nums = [-2, 0, 1, 3], and target = 2.
// Return 2. Because there are two triplets which sums are less than 2.
// [-2, 0, 1]
// [-2, 0, 3]
int threeSumSmaller(std::vector<int>& nums, int target); 
#endif
