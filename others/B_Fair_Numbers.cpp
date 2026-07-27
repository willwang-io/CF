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

bool check(ll n) {
    ll m = n;
    while (m) {
        int r = m % 10;
        if (r != 0 && n % r != 0) {
            return false;
        }
        m /= 10;
    }
    return true;
}

void solve() {
    ll n;
    std::cin >> n;
    while (!check(n)) {
        ++n;
    }
    std::cout << n << '\n';
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