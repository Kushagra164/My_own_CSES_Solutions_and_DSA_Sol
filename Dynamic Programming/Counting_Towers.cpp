#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

vector<vector<int>> dp(1e6+1,vector<int>(2));

void solve() {
    int n;
    cin >> n;
    
    dp[n][0] = 1;
    dp[n][1] = 1;
    for (int i=n-1;i>=0;i--){

        // for (int j=1;j<i;j++){
        //     // first find out for only 1 line
        //     dp[i][0] = (1LL*dp[i][0] + (dp[j][0]*1LL*dp[i-j][0])%MOD)%MOD;
        //     // second find out for 2 tiles
        //     dp[i][1] = (1LL*dp[i][1] + (dp[j][1]*1LL*dp[i-j][1])%MOD)%MOD;
        // }
        // dp[i][0] = (1LL*dp[i][0])%MOD;
        // dp[i][1] = (1LL*dp[i][1] + (2*1LL*dp[i][0])%MOD)%MOD;
        dp[i][0] = (2LL*dp[i+1][0] + dp[i+1][1])%MOD;
        dp[i][1] = (4LL*dp[i+1][1] + dp[i+1][0])%MOD;
    }
    cout << (dp[1][1]+dp[1][0])%MOD << "\n";

    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    
    while(test--) solve();
    return 0;
}