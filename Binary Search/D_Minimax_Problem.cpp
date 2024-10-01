#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

pair<bool,pair<int,int>> isPossible(vector<vector<int>> &arr,int n,int m,int mid){
    map<int,int> bitValVsidx;
    vector<int> nums;
    // cout << "mid: " << mid << "\n";
    for (int i=0;i<n;i++){
        int num=0;
        for (int j=0;j<m;j++){
            if (arr[i][j]>=mid) num |= (1<<j);
        }
        if (bitValVsidx.find(num) == bitValVsidx.end()) nums.push_back(num);
        bitValVsidx[num] = i;
        // cout << num << "\n";
    }
    int toGet = (1<<m)-1;
    int sz = nums.size();
    for (int i=0;i<sz;i++){
        for (int j=i+1;j<sz;j++){
            if ((nums[i]|nums[j]) == toGet) return {true,{bitValVsidx[nums[i]],bitValVsidx[nums[j]]}};
        }
    }
    return {false,{0,0}};
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int> (m));
    int low = INT_MAX,high = 0,mid;
    rep(i,0,n) {
        rep(j,0,m){
            cin >> arr[i][j];
            low = min(low,arr[i][j]);
            high = max(high,arr[i][j]);
        }
    }
    pair<int,int> ans;
    while(low<high){
        mid = (low+high)>>1;
        auto pos = isPossible(arr,n,m,mid);
        if (pos.first){
            ans = pos.second;
            low = mid+1; 
        }
        else high = mid;
    }
    cout << ans.first+1 << " " << ans.second+1 ;

    return ;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}