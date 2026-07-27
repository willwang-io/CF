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
    ll n, k, x;
    std::cin >> n >> k >> x;
    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    std::vector<ll> diff;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] <= x) {
            continue;
        }
        diff.push_back(a[i] - a[i - 1]);
    }
    std::sort(diff.begin(), diff.end());

    int ans = 0;
    for (auto &d: diff) {
        if ((d - 1) / x > k) {
            ++ans;
        } 
        k = std::max(0LL, k - (d - 1) / x);
    }
    std::cout << ans + 1 << '\n'; 
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    t = 1;

    for (int i = 0; i < t; ++i) {
        solve();
    }
}