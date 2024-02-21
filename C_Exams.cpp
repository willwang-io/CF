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
    std::cin >> n;
    std::vector<std::pair<int, int>> arr(n);
    for (auto &it: arr) {
        std::cin >> it.first >> it.second;
    }
    std::sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = arr[i].second < ans ? arr[i].first : arr[i].second;
    }
    std::cout << ans << '\n';
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