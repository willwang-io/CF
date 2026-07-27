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

std::vector<std::string> a[51];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cout << a[n][i] << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;

    a[1].push_back({"()"});
    for (int i = 2; i <= 50; ++i) {
        int cnt = 0;
        for (int j = 0; j < a[i - 1].size() && cnt < 50; ++j) {
            a[i].push_back("()" + a[i - 1][j]);
            a[i].push_back("(" + a[i - 1][j] + ")");
            cnt += 2;
        }
    }

    for (int i = 0; i < t; ++i) {
        solve();
    }
}
