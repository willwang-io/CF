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
    std::vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> a[i];
    }
    int prev = 1000000;
    std::cout << prev << ' ';
    for (int i = 0; i < n - 1; ++i) {
        prev += a[i];
        std::cout << prev << ' ';
    }
    std::cout << '\n';
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
