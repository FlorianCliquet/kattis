#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

// Fast input function to quickly read integers using getchar_unlocked()
inline int fast_input() {
    int x = 0;
    char c;

    // Skip non-numeric characters, check for EOF
    while ((c = getchar_unlocked()) != EOF && (c < '0' || c > '9'));

    // If we hit EOF, return a signal (e.g., -1)
    if (c == EOF) return -1;

    // Now process the number
    do {
        x = x * 10 + (c - '0');
    } while ((c = getchar_unlocked()) >= '0' && c <= '9');

    return x;
}


int main() {
    FAST_IO;
    
    while (true) {
        int n = fast_input();
        if (n == -1) break;  // Exit when -1 is encountered

        vector<int> stackArr; // Vector to simulate stack operations faster
        queue<int> queueArr;
        priority_queue<int> pqArr;

        bool isStack = true, isQueue = true, isPQ = true;

        for (int i = 0; i < n; i++) {
            int command = fast_input(), x = fast_input();

            switch (command) {
                case 1:  // Push operation
                    if (isStack) stackArr.push_back(x);
                    if (isQueue) queueArr.push(x);
                    if (isPQ) pqArr.push(x);
                    break;

                case 2:  // Pop operation
                    // Check stack
                    if (isStack) {
                        if (stackArr.empty() || stackArr.back() != x) {
                            isStack = false;
                        } else {
                            stackArr.pop_back();
                        }
                    }

                    // Check queue
                    if (isQueue) {
                        if (queueArr.empty() || queueArr.front() != x) {
                            isQueue = false;
                        } else {
                            queueArr.pop();
                        }
                    }

                    // Check priority queue
                    if (isPQ) {
                        if (pqArr.empty() || pqArr.top() != x) {
                            isPQ = false;
                        } else {
                            pqArr.pop();
                        }
                    }
                    break;
            }
        }

        // Determine the data structure based on remaining possibilities
        switch (isStack + isQueue + isPQ) {
            case 0:
                cout << "impossible\n";
                break;
            case 1:
                if (isStack) cout << "stack\n";
                else if (isQueue) cout << "queue\n";
                else if (isPQ) cout << "priority queue\n";
                break;
            default:
                cout << "not sure\n";
        }
    }

    return 0;
}
