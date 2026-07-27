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
    std::string s;
    std::cin >> s;
    int n = s.size(), ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0;
        for (int j = 0; j < n; ++j) {
            if (j <= i) {
                if (s[j] == '1') {
                    ++x;
                } else {
                    ++y;
                }
            } else {
                if (s[j] == '1') {
                    ++y;
                } else {
                    ++x;
                }
            }
        }
        ans = std::min(ans, std::min(x, y));
    }
    std::cout << ans << '\n';
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