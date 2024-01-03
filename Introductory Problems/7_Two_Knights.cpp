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
    for (int i=1;i<=n;i++){
        ll a1=i*i,a2=a1*(a1-1)/2;
        if (i>2) a2-=(4*(i-1)*(i-2));
        cout << a2 << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}