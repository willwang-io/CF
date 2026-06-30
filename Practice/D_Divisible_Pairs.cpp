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
    ll n, x, y;
    std::cin >> n >> x >> y;
    std::vector<ll> A(n);
    for (auto &a: A) {
        std::cin >> a;
    }
    std::map<int, std::map<int, int>> cnt;
    for (auto &a: A) {
        ++cnt[a % x][a % y];
    }
    ll ans = 0;
    for (auto &a: A) {
        int rx = (x - (a % x)) % x;
        ans += cnt[rx][a % y] - (a % x == rx);
    }
    std::cout << ans / 2 << '\n';
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