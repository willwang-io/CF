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

/*
 * @author: Will Wang
 * @date: 2024-12-24 15:51:37
 */
void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector<int> tmp = {a, b, c};
    std::sort(tmp.begin(), tmp.end());
    std::cout << tmp[1] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
