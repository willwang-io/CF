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
    int n;
    std::string s;
    std::cin >> n >> s;
    int ans = 0, i = 0;
    while (i < n) {
        if (i + 1 < n && s[i + 1] != '*') {
            if (s[i + 1] == '@') {
                ++ans;
            }
            ++i;
        } else if (i + 2 < n && s[i + 2] != '*') {
            if (s[i + 2] == '@') {
                ++ans;
            }
            i += 2;
        } else {
            break;
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