#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void solve() {
    int a,b;
    cin >> a >> b;
    if (a>2*b || b>2*a) {
        cout << "NO\n";
        return ;
    }
    ll c=a+b;
    if (c%3==0){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}