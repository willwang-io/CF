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
    std::vector<ll> A(n);
    for (auto &a: A) {
        std::cin >> a;
    }
    std::sort(A.begin(), A.end());
    A.resize(std::unique(A.begin(), A.end()) - A.begin());
    int j = 0, ans = 0;
    for (int i = 0; i < A.size(); ++i) {
        while (A[i] - A[j] >= n) {
            ++j;
        }
        ans = std::max(ans, i - j + 1);
    }
    std::cout << ans << '\n';
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
// Basic performance, mending, musical performance
// Basic performance, mending, musical performance
// Basic cooking, gardening, exercise