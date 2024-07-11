#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

int func(vector<int> &nums,int l,int r){
    if (r-l <= 1) return 0;
    int ans = INT_MAX;
    for (int k=l+1;k<r;k++){
        ans = min(ans,nums[r]-nums[l] + func(nums,l,k)+ func(nums,k,r));
    }
    return ans;
}

void solve() {
    int n,len;
    cin >> n >> len;
    vector<int> arr;
    arr.push_back(0);
    rep(i,0,n) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    arr.push_back(len);
    n = arr.size();
    sort(arr.begin(),arr.end());
    cout << func(arr,0,n-1) ;

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}