#include <cstddef>
#include <vector>
#include <iostream>
#include "sum_alg.h"
using namespace std;

int main() {
    vector<int> nums = {-2, 0, 1, 3, -5, 3, 5, 7, 9, 10, -6, 0, 0, 10};
    int target = 5;
    int result = threeSumSmaller(nums, target);
    cout << "The result is " << result << endl;
    return 0;
}
