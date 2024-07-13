#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define int long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

int func(vector<int> &arr,int f_idx,int l_idx,bool isPlayer1Chance,vector<vector<int>> &dp){

    if (f_idx>l_idx) return 0;
    if (dp[f_idx][l_idx] != LONG_LONG_MIN) return dp[f_idx][l_idx];
    if (isPlayer1Chance){
        int pickf = arr[f_idx] + func(arr,f_idx+1,l_idx,0,dp);
        int pickl = arr[l_idx] + func(arr,f_idx,l_idx-1,0,dp);
        return dp[f_idx][l_idx] = max(pickf,pickl);
    }
    int pickf = func(arr,f_idx+1,l_idx,1,dp);
    int pickl = func(arr,f_idx,l_idx-1,1,dp);
    return dp[f_idx][l_idx] = min(pickf,pickl);
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n,vector<int>(n,LONG_LONG_MIN));
    cout << func(arr,0,n-1,1,dp) ;

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}