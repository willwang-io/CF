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

using ll = long long;

void solve() {
    ll n, k;
    std::cin >> n >> k;
    for (ll i = 0; i <= sqrt(2 * (n + k)); ++i) {
        if (i * (i + 3) == 2 * (n + k)) {
            std::cout << n - i << '\n';
            return;
        }
    }
    std::cout << 0 << '\n';
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