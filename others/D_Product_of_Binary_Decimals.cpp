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

int bin(int x) {
    std::string ans;
    while (x) {
        ans = std::string(1, (x & 1) + '0') + ans; 
        x >>= 1;
    }
    return std::stoi(ans);
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a;
    for (int i = 2; i < 32; ++i) {
        a.push_back(bin(i));
    }
    int m = a.size();
    for (int i = m - 1; i >= 0; --i) {
        while (n && n % a[i] == 0) {
            n /= a[i];
        }
    }
    std::cout << (n == 1 ? "YES\n" : "NO\n");
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
