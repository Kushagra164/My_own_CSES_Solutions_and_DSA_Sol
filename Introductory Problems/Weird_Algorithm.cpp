#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define int long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void solve() {
    int n;
    cin >> n;
    cout << n << " ";
    while(n!=1){
        if (n&1) {
            n *= 3;
            n++;
        } 
        else n /= 2;
        cout << n << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}