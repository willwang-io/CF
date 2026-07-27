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
    std::map<int, int> cnt, idx;
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        idx[a[i]] = -1;
        cnt[a[i]] = 0;
    }
    if (idx.size() == 1) {
        std::cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (i - idx[a[i]] > 1) {
            ++cnt[a[i]];
        }
        idx[a[i]] = i;
    }
    int ans = 1e9;
    for (auto &it: cnt) {
        if (idx[it.first] != n - 1) {
            ++it.second;
        }
        ans = std::min(ans, it.second);
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