#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

// 454 4Sum II
// Give four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
// Take make problem a bit easier, all A, B, C, D have same length of N where 0 <= N <= 500. All integers are in the range of -2^28 to 2^28-1 and the result is guaranteed to be at most 2^31 - 1
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> mpAB;

    for (int a : A) {
        for (int b : B) {
            mpAB[a + b]++;
        }
    }

    int result = 0;
    for(int c : C) {
        for (int d : D) {
            auto abIt = mpAB.find(-(c+d));
            if (mpAB.end() != abIt) {
                result += abIt->second;
            }
        }
    }

    return result;
}

// 18 4Sum
// Given an array S of n integers, are there elements a, b, c and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target
// The solution set must not contain duplicate quadruplets
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (4 > nums.size()) return result;     // The array size needs to be at least 4

    // sort the array first
    sort (nums.begin(), nums.end());

    // Outer two loops defines the boundary of searching
    for(int i = 0; i < nums.size() - 3; i++) {
        if ((nums[i] << 2) > target) return result;      // If the smallest element in this 4 number group is larget than target / 4,
                                                        // then there is no solution beyond the element
        for(int j = nums.size() - 1; j >= i + 3; j--) {
            if ((nums[j] << 2) < target) break;
            int lo = i + 1;
            int hi = j - 1;
            while (lo < hi) {
                int rem = target - nums[i] - nums[j];
                if (nums[lo] + nums[hi] > rem) lo++;    // adjusting the lo and hi to find a match of rem
                else if (nums[lo] + nums[hi] > rem) hi--;
                else {
                    // a match is found
                    vector<int> entry = {nums[i], nums[lo], nums[hi], nums[j]}; // note that this initialization method is only valid after C++11 standard
                    result.push_back(entry);
                    while (++lo < hi && nums[lo] == nums[lo - 1]);
                    while (lo < --hi && nums[hi] == nums[hi + 1]);
                }
                while (j > i && nums[j] == nums[j - 1]) --j;
            }
            while (i < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
    }
    return result;
}

// 15 3Sum
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (3 > nums.size()) return result; // The array size needs to be at least 3

    // sort the array first
    sort(nums.begin(), nums.end());

    // Outer loop determine the starting element for 3sum search
    for(int i = 0; i < nums.size() - 2; i++) {
        int lo = i + 1;
        int hi = nums.size() - 1;
        while (lo < hi) {
            if (nums[lo] + nums[hi] < -nums[i]) lo++;
            else if (nums[lo] + nums[hi] > -nums[i]) hi--;
            else {
                vector<int> entry = {nums[i], nums[lo], nums[hi]};  // note that this initialization method is only valid after C++11 standard
                result.push_back(entry);
                while (++lo < hi && nums[lo] == nums[lo - 1]);
                while (lo < --hi && nums[hi] == nums[hi + 1]);
            }
        }
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
    }
    return result;
}

// 16 3Sum Closest Given an array S of n integers, find three integers in  such
// that the sum is closest to a given number, target. Return the sum of the
// three integers. You may assume that each input would have exactly one
// solution
int threeSumClosest(vector<int>& nums, int target) {
    if (3 > nums.size()) return 0;

    // sort the array
    sort(nums.begin(), nums.end());

    int gap = abs(target - nums[0] - nums[1] - nums[2]);
    int result = nums[0] + nums[1] + nums[2];

    // define the left boundary
    for (int i = 0; i < nums.size() - 2; i++) {
        int lo = i + 1;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int sum_temp = nums[i] + nums[lo] + nums[hi];
            int rem = target - sum_temp;
            if (rem > 0) lo++;
            else if (rem < 0) hi--;
            else {
                return sum_temp;
            }
            if (abs(rem) < gap) {
                gap = abs(rem);
                result = sum_temp;
            }
        }
        while (i < nums.size() - 1 && nums[i + 1] == nums[i]) i++;
    }
    return result;
}

// 259. 3Sum smaller
// Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that 
// satisfy the condition nums[i] + nums[j] + nums[k] < target
// For example, given nums = [-2, 0, 1, 3], and target = 2.
// Return 2. Because there are two triplets which sums are less than 2.
// [-2, 0, 1]
// [-2, 0, 3]
int threeSumSmaller(vector<int>& nums, int target) {
    if (3 > nums.size()) return 0;
    sort(nums.begin(), nums.end());

    int result = 0;
    for (int i = 0; i < nums.size() - 2; i++) {
        int lo = i + 1;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int sum_temp = nums[i] + nums[lo] + nums[hi];
            if (sum_temp < target) {
                result += (hi - lo);
                lo++;
            } else {
                while (lo < --hi && nums[hi+1] == nums[hi]);
            }
        }
    }

    return result;
}
