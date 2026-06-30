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
    int h = std::stoi(s.substr(0, 2)), m = std::stoi(s.substr(3, 2));
    std::string t = (h >= 0 && h < 12) ? "AM" : "PM";
    if (h == 0) {
        h += 12;
    }
    if (h > 12) {
        h -= 12;
    }
    if (h < 10) {
        std::cout << 0;
    }
    std::cout << h << ':';
    if (m < 10) {
        std::cout << 0;
    }
    std::cout << m << ' ' << t << '\n';
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
