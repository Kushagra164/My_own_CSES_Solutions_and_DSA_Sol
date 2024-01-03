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
    vector<int> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i=1;i<n;i++){
        if (arr[i]>=arr[i-1]) continue;
        int dif = arr[i-1]-arr[i];
        ans += dif;
        arr[i] += dif;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}