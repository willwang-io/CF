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
    ll total = 0LL;
    for (auto &a: A) {
        std::cin >> a;
        total += a;
    }
    ll m = total / n, r = 0LL;
    for (int i = 0; i < n; ++i) {
        if (A[i] > m) {
            r += (A[i] - m);
        } else {
            ll need = m - A[i];
            if (need > r) {
                std::cout << "NO\n";
                return;
            }
            r -= need;
        }
    }
    std::cout << "YES\n";
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