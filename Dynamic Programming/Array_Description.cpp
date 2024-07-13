#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

int func(vector<int> &nums,int idx,int prevNum,int m,vector<vector<int>> &dp){
    if (idx == (int)nums.size()) return 1;
    if (dp[idx][prevNum] != -1) return dp[idx][prevNum];
    if (nums[idx] != 0){
        if (abs(nums[idx]-prevNum) > 1) return 0;
        return dp[idx][prevNum] = func(nums,idx+1,nums[idx],m,dp);
    }
    int cnt = 0;
    cnt = (func(nums,idx+1,prevNum,m,dp))%MOD;
    if (prevNum + 1 <= m) cnt= (1LL*cnt + 1LL*func(nums,idx+1,prevNum+1,m,dp))%MOD;
    if (prevNum-1 > 0) cnt= (cnt*1LL + 1LL*func(nums,idx+1,prevNum-1,m,dp))%MOD;
    return dp[idx][prevNum] = cnt;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }
    // map<pair<int,int>,int> dp;
    vector<vector<int>> dp(n,vector<int>(m+1,-1));
    int cnt = 0;
    if (arr[0] == 0){
        for(int i=1;i<=m;i++) cnt = (cnt*1LL + 1LL*func(arr,1,i,m,dp))%MOD;
    }
    else cnt = func(arr,1,arr[0],m,dp);
    cout << cnt ;

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}