#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a;
    int last = -1, cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x != last) {
            if (cnt > 0) {
                a.push_back(cnt);
            }
            last = x;
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    a.push_back(cnt);

    std::sort(a.begin(), a.end());

    ll s = n, m = a.size(), ans = 0;
    int i = 0;
    while (i < a.size()) {
        int q = a[i];
        if ((s - k) % m == 0) {
            ll x = (s - k) / m;
            if (x + 1 <= q) {
                ++ans;
            }
        }
        while (i < a.size() && a[i] == q) {
            s -= a[i];
            --m;
            ++i;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}