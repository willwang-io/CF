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

using ll = long long;

void solve() {
    ll r, x, y, xx, yy;
    std::cin >> r >> x >> y >> xx >> yy;
    ll dist = (xx - x) * (xx - x) + (yy - y) * (yy - y);
    std::cout << ceil(sqrt(dist) / (2 * r)) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;

    for (int i = 0; i < t; ++i) {
        solve();
    }
}