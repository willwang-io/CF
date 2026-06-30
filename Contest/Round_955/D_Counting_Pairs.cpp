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
typedef std::vector<int> vi;

ll helper(vi a, ll x) {
    size_t j = 0, n = a.size();
    ll ans = 0LL, total = std::accumulate(a.begin(), a.end(), 0LL);
    for (int i = n - 1; i >= 0; --i) {
        while (j < n && total - a[i] - a[j] >= x) {
            ++j;
        }
        ans += (n - j);
    } 
    for (size_t i = 0; i < n; ++i) {
        if (total - a[i] - a[i] < x) {
            --ans;
        }
    }
    return ans / 2;
}

void solve() {
    ll n, x, y;
    std::cin >> n >> x >> y;
    vi a(n);
    for (auto &i: a) {
        std::cin >> i;
    }
    std::sort(a.begin(), a.end());
    std::cout << helper(a, y + 1) - helper(a, x) << '\n';
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