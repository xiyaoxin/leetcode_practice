#include <climits>
#include <cstdlib>
using namespace std;

int divide(int dividend, int divisor) {
    if (0 == divisor || (INT_MIN == dividend && -1 == divisor)) return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    long long ldivnd = labs((long long)dividend);
    long long ldivsr = labs((long long)divisor);

    long long result = 0;

    while (ldivnd >= ldivsr) {
        long long bitTracker = ldivsr;
        long long bitRecorder = 1;

        while ((bitTracker << 1) < ldivnd) {
            bitTracker = bitTracker << 1;
            bitRecorder = bitRecorder << 1;
        }

        ldivnd -= bitTracker;
        result += bitRecorder;
    }

    return sign > 0 ? result : -result;
}
