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

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int i = 2, j = n - 2, cnt1 = 2, cnt2 = 1;
    ll blue = a[0] + a[1], red = a[n - 1];
    while (i <= j) {
        if (blue < red && cnt1 > cnt2) {
            std::cout << "YES\n";
            return;
        }
        if (blue >= red) {
            red += a[j];
            ++cnt2, --j;
        } else if (cnt1 <= cnt2) {
            blue += a[i];
            ++cnt1;
            ++i;
        }
    }
    if (blue < red && cnt1 > cnt2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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
