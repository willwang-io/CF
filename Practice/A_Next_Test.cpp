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
    int n;
    std::cin >> n;
    std::vector<int> a(3002);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= 3001; ++i) {
        if (a[i] == 0) {
            std::cout << i << '\n';
            return;
        }
    }
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
