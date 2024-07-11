#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

int func(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for (int k=i;k<j;k++) ans = min(ans,func(nums,i,k,dp)+func(nums,k+1,j,dp)+nums[i-1]*nums[k]*nums[j]);
    return dp[i][j] = ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) cin >> nums[i];
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout << func(nums,1,n-1,dp) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--) solve();
    return 0;
}