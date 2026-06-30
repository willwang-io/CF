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
    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    ll ans = 0;
    if (a[0] != 1) {
        ans += (a[0] - 1);
        a[0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > 1) {
            ans += (a[i] - a[i - 1] - 1);
            a[i] = a[i - 1] + 1;
        }
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