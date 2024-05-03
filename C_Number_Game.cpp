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

#define A "Ashishgup\n"
#define B "FastestFinger\n"

bool is_prime(ll x){
    if (x <= 1) {
        return false;
    }
    if (x == 2 || x == 3) {
        return true;
    }
    if (x % 2 == 0 || x % 3 == 0) {
        return false;
    }
    if ((x - 1) % 6 != 0 && (x + 1) % 6 != 0) {
        return false;
    }
    for (ll i = 5; i * i <= x; i += 6) {
        if(x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << B;
    }else if (n == 2) {
        std::cout << A;
    } else if ((n & (n - 1)) == 0) {
        std::cout << B;
    } else if (n % 2 == 0) {
        int p = n / 2;
        if (is_prime(p)) {
            std::cout << B;
        } else {
            std::cout << A;
        }
    } else {
        std::cout << A;
    }
    
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
