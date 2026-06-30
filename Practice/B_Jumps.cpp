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
    ll x;
    std::cin >> x;
    ll n = 0;
    while (true) {
        if (n * (n + 1) / 2 >= x) {
            break;
        }
        ++n;
    }
    if (n * (n + 1) / 2 == x + 1) {
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