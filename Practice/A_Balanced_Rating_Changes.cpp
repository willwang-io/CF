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

using ll = long long;

void solve() {
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    int flag = 1;
    for (auto &a: A) {
        std::cin >> a;
        if (a % 2 == 0) {
            std::cout << a / 2 << '\n';
        } else {
            std::cout << (a + flag) / 2 << '\n';
            flag *= -1;
        }
    }
}