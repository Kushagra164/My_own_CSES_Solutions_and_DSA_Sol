#include <bits/stdc++.h>
using namespace std;
#define int long long

int query(vector<int> &sizes,map<int,pair<int,int>> mp,int idx){
    int dst = lower_bound(sizes.begin(),sizes.end(),idx)-sizes.begin();
    if (sizes[dst] == idx && mp[dst].first == 1) return mp[dst].second;
    return idx%mp[dst].second != 0 ? query(sizes,mp,idx%mp[dst].second):query(sizes,mp,mp[dst].second) ;
}

void solve(){
    int n,q,curr=0,idx=0;
    cin >> n >> q;
    vector<int> sizes;
    map<int,pair<int,int>> mp;
    for(int i=0;i<n;i++){
        int type,x;
        cin >> type >> x;
        if (type == 1){
            curr++;
            sizes.push_back(curr);
            mp[idx] = {type,x};
        }
        else{
            mp[idx] = {type,curr};
            curr = min((long long)1e18,(x+1)*curr);
            sizes.push_back(curr);
        }
        idx++;
    }
    while(q--){
        int f_idx;
        cin >> f_idx;
        cout << query(sizes,mp,f_idx) << " ";
    }
}

signed main() {
    solve();
    return 0;
}