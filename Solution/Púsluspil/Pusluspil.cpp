#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

inline int fast_input() {
    int x = 0;
    char c;
    while ((c = getchar_unlocked()) < '0' || c > '9');
    do {
        x = x * 10 + (c - '0');
    } while ((c = getchar_unlocked()) >= '0' && c <= '9');
    return x;
}

int main() {
    FAST_IO
    int n = fast_input(), m = fast_input();
    bool present[m + 1] = {false};
    int total_present = 0;

    for (int i = 0; i < n; ++i) {
        int k = fast_input();
        for (int j = 0; j < k; ++j) {
            int x = fast_input();
            if (x <= m && !present[x]) {
                present[x] = true;
                total_present++;
            }
        }
    }

    puts(total_present == m ? "Jebb" : "Neibb");
    
    return 0;
}