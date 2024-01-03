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
    int sum = (n*(n+1))>>1, sum_temp = 0;
    // vector<int> arr(n-1);
    rep(i,0,n-1) {
        int x;
        cin >> x;
        sum_temp += x;
    }

    cout << sum - sum_temp ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}