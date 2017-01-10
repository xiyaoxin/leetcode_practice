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
#endif
