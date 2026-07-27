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
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, v;
    std::cin >> n >> v;
    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        std::vector<int> a(m);
        for (auto &x: a) {
            std::cin >> x;
        }
        std::sort(a.begin(), a.end());
        if (a[0] + 1 <= v) {
            ans.push_back(i + 1);
        }
    }
    std::cout << ans.size() << '\n';
    for (auto &i: ans) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}