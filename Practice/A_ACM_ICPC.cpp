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
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<int> a(6);
    int total = 0;
    for (auto &i: a) {
        std::cin >> i;
        total += i;
    }
    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            for (int k = j + 1; k < 6; ++k) {
                int cur = a[i] + a[j] + a[k];
                if (total - cur == cur) {
                    std::cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    std::cout << "NO\n";
}