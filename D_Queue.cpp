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

void solve() {
    int n;
    std::cin >> n;
    vi a(n);
    for (int &x: a) {
        std::cin >> x;
    }
    std::sort(a.begin(), a.end());
    for (auto &x: a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    ll ans = 0, time = a[0];
    for (int i = 1; i < n; ++i) {
        if (time > a[i]) {
            std::cout << i << ' ' << time << ' ' << a[i] << '\n';
            ++ans;
        }
        time += a[i];
    }
    std::cout << n - ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;
    while (t--) {
        solve();
    }
}