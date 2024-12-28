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
 * @date: 2024-12-24 21:03:16
 */
void solve() {
    int n, k;
    std::cin >> n >> k;
    if (n <= k) {
        std::cout << 1 << '\n';
        return;
    }
    std::vector<int> d;
    for (int i = 1; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            d.push_back(i);
            if (n / i != i) {
                d.push_back(n / i);
            }
        }
    }
    std::sort(d.rbegin(), d.rend());
    for (auto &x: d) {
        if (x <= k) {
            std::cout << n / x << '\n';
            return;
        }
    }
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
