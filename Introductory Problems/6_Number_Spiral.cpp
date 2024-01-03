#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void solve() {
    ll x,y;
    cin >> x >> y;
    ll n;
    if (x<=y){
        if (y%2==0) n=((y-1)*(y-1))+x;
        else n=(y*y)-x+1;
    }
    else {
        if (x%2==0) n=(x*x)-y+1;
        else n=((x-1)*(x-1))+y;
    }
    cout << n << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;cin >> test;
    while(test--){
        solve();
    }
    return 0;
}