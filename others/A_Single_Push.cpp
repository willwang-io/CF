#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>

using ll = long long;

void solve() {
    int n; 
    std::cin >> n;
    std::vector<int> A(n), B(n);
    for (auto &a: A) {
        std::cin >> a;
    }
    for (auto &b: B) {
        std::cin >> b;
    }
    for (int i = 0; i < n; ++i) {
        if (B[i] > A[i]) {
            int diff = B[i] - A[i];
            while (i < n && B[i] > A[i]) {
                A[i] += diff;
                ++i;
            }
            break;
        }
    }
    std::cout << (A == B ? "YES\n" : "NO\n");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }
}