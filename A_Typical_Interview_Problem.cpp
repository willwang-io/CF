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
    int k;
    std::string s;
    std::cin >> k >> s;
    std::string tmp;
    for (int i = 1; i < 500; ++i) {
        if (i % 3 == 0) {
            tmp += 'F';
        }
        if (i % 5 == 0) {
            tmp += 'B';
        }
    }
    for (int i = 0; i < tmp.size() - s.size() + 1; ++i) {
        auto cur = tmp.substr(i, s.size());
        if (cur == s) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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
