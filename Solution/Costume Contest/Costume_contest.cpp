#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    map<string,int> m; string a;
    while(t--) cin >> a, m[a]++;
    int mn=INT_MAX; for(auto &p:m) mn=min(mn,p.second);
    for(auto &p:m) if(p.second==mn) cout << p.first << "\n";
}

int main() {
    int t; cin >> t; solve(t);
}