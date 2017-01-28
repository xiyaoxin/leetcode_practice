#include <vector>
#include <iostream>
#include "arr_alg.h"
using namespace std;

int main() {
    vector<int> vec = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 1, 2, 3, 4, 5, 6};
    int target = 16;
    int result = search(vec, target);
    cout << "result = " << result << endl;
    return 0;
}
