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
    int x, n;
    std::cin >> x >> n;
    int ans = 1;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            if (n <= x / i) {
                ans = std::max(ans, i);
            }
            if (n <= i) {
                ans = std::max(ans, x / i);
            }
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