#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void solve() {
    int n,target;
    cin >> n >> target;
    vector<int> arr(n);
    rep(i,0,n) cin >> arr[i];
    if (n < 4) {
        cout << "IMPOSSIBLE";
        return ;
    }
    map<int,vector<pair<int,int>>> mp;
    for (int i=0;i<n-1;i++) for (int j=i+1;j<n;j++) mp[arr[i]+arr[j]].pb({i,j});
    vector<int>  ans = {-1,-1,-1,-1};
    for (auto m:mp){
        int val = m.first;
        if (val >= target) break;
        if (mp.find(target - val) != mp.end()){
            auto vec1 = m.second;
            auto vec2 = mp[target-val];
            for (int i=0;i<vec1.size();i++){
                for (int j=0;j<vec2.size();j++){
                    if (vec1[i].first != vec2[j].first && vec1[i].first != vec2[j].second && vec1[i].second != vec2[j].first && vec1[i].second != vec2[j].second){
                        ans[0] = vec1[i].first;
                        ans[1] = vec1[i].second;
                        ans[2] = vec2[j].first;
                        ans[3] = vec2[j].second;
                        for (int i=0;i<4;i++) cout << ans[i]+1 << " " ;
                        return ;
                    }
                }
            }
        }
    }
    if (ans[0] == -1){
        cout << "IMPOSSIBLE";
        return ;
    }
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}