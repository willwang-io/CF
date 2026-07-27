#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

long long n;
std::map<long long, int> dp;

int dfs(long long n) {
    if (n == 0) {
        return 0;
    }
    if (dp.find(n) != dp.end()) {
        return dp[n];
    }
    std::string s = std::to_string(n);
    int ans = 1e9;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            continue;
        }
        ans = std::min(ans, 1 + dfs(n - (s[i] - '0')));
    }
    return dp[n] = ans;
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    std::cout << dfs(n) << '\n';

    return 0;
}