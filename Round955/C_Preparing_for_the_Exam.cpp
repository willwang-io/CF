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
#include <bitset>

typedef long long ll;
typedef std::vector<int> vi;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    vi a(m);
    std::string known(n, '0');
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        size_t x;
        std::cin >> x;
        known[x - 1] = '1';
    }
    if (k == n) {
        std::cout << std::string(m, '1') << '\n';
        return;
    }
    if (n - k != 1) {
        std::cout << std::string(m, '0') << '\n';
        return;
    }
    std::string ans;
    for (int &x: a) {
        if (known[x - 1] == '0') {
            ans += '1';
        } else {
            ans += '0';
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
}