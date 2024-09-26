#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

// Fast input function to quickly read integers using getchar()
inline int fast_input() {
    int x = 0;
    char c;

    // Skip non-numeric characters, check for EOF
    while ((c = getchar()) != EOF && (c < '0' || c > '9'));

    // If we hit EOF, return a signal (e.g., -1)
    if (c == EOF) return -1;

    // Now process the number
    do {
        x = x * 10 + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');

    return x;
}

int main() {
    FAST_IO;

    int n = fast_input(), m = fast_input();
    vector<int> roll(n);
    int total_sum = 0;

    // Read clusters and calculate the total sum T
    for (int i = 0; i < n; i++) {
        roll[i] = fast_input();
        total_sum += roll[i];
    }

    // Answer each query
    for (int i = 0; i < m; i++) {
        int query = fast_input();
        int target_sum = total_sum - query;  // We are looking for a subarray sum equal to T - q

        // Sliding window approach to find if a subarray sums to target_sum
        int current_sum = 0, start = 0;
        bool found = false;

        for (int end = 0; end < n && (found == false); end++) {
            current_sum += roll[end];  // Expand the window

            // Shrink the window if current_sum exceeds the target
            while (current_sum > target_sum && start <= end) {
                current_sum -= roll[start];
                start++;
            }

            // If we find a subarray with the target sum
            found = (current_sum == target_sum);
        }

        // Output result for this query
        puts(found ? "Yes" : "No");
    }

    return 0;
}