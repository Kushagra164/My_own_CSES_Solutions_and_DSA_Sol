#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void buildnums(vector<int> &nums,int n,vector<bool> &dp){
    int i=1;
    while(i*i<=n){
        nums.push_back(i*i);
        dp[i*i]=true;
        i++;
    }
    return ;
}

bool winnerSquareGame(int n) {
    vector<int> nums;
    vector<bool> dp(n+1,false);
    buildnums(nums,n,dp);
    int sz = nums.size();
    // cout << "ok";
    for (int i=2;i<=n;i++){
        if (dp[i] == true) continue;
        bool temp = false;
        int j = 0;
        while(j<sz && i-nums[j] >= 0){
            temp |= ((dp[i-nums[j]])^1);
            cout << "i : " << i << " j : " << j << " temp : " << temp << "\n";
            j++;
        }
        dp[i]=temp;
    }
    return dp[n];
}

void solve() {
    int n;
    cin >> n ;
    cout << winnerSquareGame(n) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--)
    solve();
    return 0;
}