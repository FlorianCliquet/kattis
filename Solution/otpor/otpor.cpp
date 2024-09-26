// Include everything
#include <bits/stdc++.h>

// Optimization
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

// Struct to represent an expression of resistances (either in series or parallel)
struct Expr {
    bool series = true;
    vector<long double> R;

    long double eval() {
        long double result = 0.0;
        if (series) {
            for (long double r : R) result += r;
        } else {
            for (long double r : R) result += 1.0 / r;
            result = 1.0 / result;
        }
        return result;
    }
};

int main() {
    FAST_IO

    int N;
    cin >> N;
    vector<long double> R(N);
    for (int i = 0; i < N; ++i) {
        cin >> R[i];
    }

    string expression;
    cin >> expression;

    stack<Expr> exprStack;
    long double result = 0.0;

    for (char ch : expression) {
        if (ch == '(') {
            exprStack.push(Expr()); // Push an empty item of Expr
        } else if (ch >= '1' && ch <= '9') {
            int index = ch - '1';
            exprStack.top().R.push_back(R[index]); // Update the vector inside Expr
        } else if (ch == '-') {
            exprStack.top().series = true; // Change series state of Expr
        } else if (ch == '|') {
            exprStack.top().series = false;
        } else if (ch == ')') {
            long double evaluated = exprStack.top().eval(); // Get the actual value inside top stack
            exprStack.pop(); // Remove this from stack
            if (exprStack.empty()) { // If stack is now empty it's our final value
                result = evaluated;
            } else {
                exprStack.top().R.push_back(evaluated); // Push evaluated value into the new top value of the stack
            }
        }
    }

    // Output result with 6 decimal precision
    cout << fixed << setprecision(6) << result << endl;
    return 0;
}
