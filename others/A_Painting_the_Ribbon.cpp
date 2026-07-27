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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> pieces(n);
    for (int i = 0; i < n; ++i) {
        pieces[i] = i % m;
    }
    int mn = 1e9;
    for (int i = 0; i < m; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (pieces[j] != i) {
                ++cur;
            }
        }
        mn = std::min(mn, cur);
    }
    std::cout << (mn > k ? "YES\n" : "NO\n");
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
