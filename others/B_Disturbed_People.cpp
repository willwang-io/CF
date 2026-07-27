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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x: a) {
        std::cin >> x;
    }
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
            a[i + 1] = 0;
            ++ans;
        }
    }
    std::cout << ans << '\n';
}