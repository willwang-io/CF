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
    std::vector<int> A(n);
    for (auto &a: A) {
        std::cin >> a;
    }
    int i = 0; 
    while (i < n && A[i] == A[0]) {
        ++i;
    }
    int j = n - 1;
    while (j >= 0 && A[n - 1] == A[j]) {
        --j;
    }
    if (A[0] != A[n - 1]) {
        std::cout << std::min(n - i, j + 1) << '\n';
    } else {
        std::cout << std::max(0, j - i + 1) << '\n';
    }
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