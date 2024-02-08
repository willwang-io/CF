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
    int n, k; 
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    for (int i = 0; i < n && k; ++i) {
        if (i == 0) {
            if (n == 1) {
                s[i] = '0';
                --k;
            } else {
                if (s[i] != '1') {
                    --k;
                }
                s[i] = '1';
            }
        } else {
            if (s[i] != '0') {
                --k;
            }
            s[i] = '0';
        }
    }
    std::cout << s << '\n';
}