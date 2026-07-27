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
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::vector<int> a(n);
    for (auto &i: a) {
        std::cin >> i;
    }
    std::cin >> s;
    int l = 0, r = n - 1;
    std::vector<int> idx;
    for (auto &c: s) {
        if (c == 'R') {
            idx.push_back(r);
            --r;
        } else {
            idx.push_back(l);
            ++l;
        }
    }
    std::reverse(idx.begin(), idx.end());
    std::vector<int> ans;
    int prod = 1;
    for (auto &i: idx) {
        prod = (prod * a[i]) % m;
        ans.push_back(prod);
    }
    std::reverse(ans.begin(), ans.end());
    for (auto &i: ans) {
        std::cout << i << ' ';
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