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
 * @date: 2024-12-24 15:39:36
 */
void solve() {
    ll m, a, b, c;
    std::cin >> m >> a >> b >> c;
    ll ans = 0LL, x = m, y = m;
    ans += std::min(x, a);
    x = std::max(0LL, x - a);
    ans += std::min(y, b);
    y = std::max(0LL, y - b);
    ans += std::min(x + y, c);
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
