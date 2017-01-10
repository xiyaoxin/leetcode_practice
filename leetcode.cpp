#include <cstddef>
#include <vector>
#include <iostream>
#include "sum_alg.h"
using namespace std;

int main() {
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};

    int result = fourSumCount(A, B, C, D);
    cout << "4Sum count: " << result << endl;
    return 0;
}
