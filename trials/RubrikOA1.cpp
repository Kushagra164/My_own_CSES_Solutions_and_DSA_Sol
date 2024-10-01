#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> val(n+1);
    rep(i,1,n+1) {
        cin >> val[i];
    }
    vector<int> adj_list[n+1];
    for (int i=2;i<=n;i++){
        int par;
        cin >> par;
        adj_list[i].push_back(par);
        adj_list[par].push_back(i);
    }
    int ans = 0;
    dfs(adj_list,1,ans);
    cout << ans << "\n";
}

signed main() {
    solve();
    return 0;
}