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

typedef long long ll;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        if (t[i] == 1) {
            ans += a[i];
            a[i] = 0;
        }
    }
    std::vector<ll> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[i] += p[i - 1] + a[i - 1];
    }
    ll mx = 0LL;
    for (int i = k; i <= n; ++i) {
        mx = std::max(mx, p[i] - p[i - k]);
    }
    std::cout << ans + mx << '\n';
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
