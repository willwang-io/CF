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
#include <cstring>

using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n), b(n);
    for (auto &it: a) {
        std::cin >> it;
    }
    for (auto &it: b) {
        std::cin >> it;
    }
    std::vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] - b[i];
    }
    ll ans = 0;
    std::sort(c.begin(), c.end());
    for (int i = 0; i < n; ++i) {
        if (c[i] <= 0) {
            continue;
        }
        auto idx = std::upper_bound(c.begin(), c.end(), -c[i]) - c.begin();
        ans += i - idx;
    }
    std::cout << ans << '\n';
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