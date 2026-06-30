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
    ll a, s;
    std::cin >> a >> s;
    std::string ans;
    while (a && s) {
        if (s % 10 < a % 10) {
            int tmp = s % 100 - a % 10;
            if (tmp > 9 || tmp < 0) {
                std::cout << -1 << '\n';
                return;
            }
            ans = std::to_string(tmp) + ans;
            s /= 100;
        } else {
            ans = std::to_string(s % 10 - a % 10) + ans;
            s /= 10;
        }
        a /= 10;
        if (a > s) {
            std::cout << -1 << '\n';
            return;
        }
    }
    ans = std::to_string(s) + ans;
    ans.erase(0, ans.find_first_not_of('0'));
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