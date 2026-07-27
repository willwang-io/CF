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

/*
 * @author: Will Wang
 * @date: 2024-12-24 15:51:37
 */
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> cnt(21);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ++cnt[x];
    }
    int ans = 0;
    for (int i = 1; i <= 20; ++i) {
        ans += cnt[i] / 2;
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
