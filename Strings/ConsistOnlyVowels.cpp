#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void solve() {
    int n;
    cin >> n;
    int a = 1, e = 1, i = 1, o = 1, u = 1;
    for (int k=2;k<=n;k++){
        a += e+i+o+u;
        e += i+o+u;
        i += o+u;
        o += u; 
    }
    cout << a + e + i + o + u;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}