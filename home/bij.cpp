#include <cstdint>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

using i64 = uint64_t;
// Compute C(n, k)
i64 comb(int n, int k) {
    i64 res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - i + 1) / i;
    return res;
}

// Get the index-th number with k bits set in n-bit numbers (0-based index)
unsigned int nth_combination(int n, int k, i64 index) {
    unsigned int result = 0;
    int bit = 0;
    while (k) {
        i64 c = comb(n - 1 - bit, k - 1);
        if (index < c) {
            result |= 1u << (n - 1 - bit);
            --k;
        } else {
            index -= c;
        }
        ++bit;
    }
    return result;
}

// Main bijection function: i in [1, 2^29 - 1]
i64 bijection(i64 i) {
    i64 total = 0;
    for (int k = 1; k <= 20; ++k) {
        i64 c = comb(20, k);
        if (total + c >= i) {
            i64 offset = i - total - 1;
            return nth_combination(20, k, offset);
        }
        total += c;
    }
    return -1;
}

int main() {
    // Print the first 50 values
    for (int i = 1; true; ++i) {
        i64 val = bijection(i);
        if (val == -1)
            return 0;
        cout << i << ": " << bitset<20>(val) << "= " << val << endl;
    }
    return 0;
}

