#ifndef SUM_ALG_H
#define SUM_ALG_H

// 454 4Sum II
// Give four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
// Take make problem a bit easier, all A, B, C, D have same length of N where 0 <= N <= 500. All integers are in the range of -2^28 to 2^28-1 and the result is guaranteed to be at most 2^31 - 1
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D); 

#endif
