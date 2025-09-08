#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return true;
            num /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = n - 1; a > 0; a--) {
            int b = n - a;
            if (!hasZero(a) && !hasZero(b)) {
                return {a, b};
            }
        }
        return {};
    }
};