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
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<std::vector<int>> a = {{}, {}, {2}, {3}, {3, 2, 2}, {5}, {5, 3}, {7}, {7, 2, 2, 2}, {7, 3, 3, 2}};
    std::vector<int> b;
    for (auto &c: s) {
        for (auto &i: a[c - '0']) {
            b.push_back(i);
        }
    }
    std::sort(b.begin(), b.end(), std::greater());
    for (auto &i: b) {
        std::cout << i;
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    t = 1;

    for (int i = 0; i < t; ++i) {
        solve();
    }
}