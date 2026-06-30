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
    ll n, a, b, c;
    std::cin >> n >> a >> b >> c;
    ll total = a + b + c;
    ll cnt = n / total;
    ll ans = cnt * 3;
    ll cur = total * cnt;
    if (cur < n) {
        cur += a;
        ++ans;
    }
    if (cur < n) {
        cur += b;
        ++ans;
    }
    if (cur < n) {
        cur += c;
        ++ans;
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