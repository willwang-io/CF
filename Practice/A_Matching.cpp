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
    std::string s;
    std::cin >> s;
    if (s[0] == '0') {
        std::cout << 0 << '\n';
        return;
    }
    ll ans = 1LL;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            if (i == 0) {
                ans *= 9;
            } else {
                ans *= 10;
            }
        }
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
