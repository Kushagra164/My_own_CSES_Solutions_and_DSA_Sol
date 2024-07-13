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
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dp[1][0] = 1;
    dp[1][1] = 2;
    for (int i=2;i<=n;i++){
        
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--) solve();
    return 0;
}