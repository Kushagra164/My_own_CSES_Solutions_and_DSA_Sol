#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void dfs1(vector<int> adj_list[],int node,int par,set<pair<int,int>> &broken,vector<bool> &isbroken){
    for (auto child:adj_list[node]){
        if (child != par){
            if (broken.find({child,node}) != broken.end()) isbroken[child]=1;
            dfs1(adj_list,child,node,broken,isbroken);
        }
    }
}

pair<bool,int> dfs(vector<int> adj_list[],int node,int par,vector<bool> &isbroken,vector<int> &ans){
    pair<bool,int> res = {0,0};
    for (auto child:adj_list[node]){
        if (child == par) continue;
        auto temp = dfs(adj_list,child,node,isbroken,ans);
        if (!temp.first) continue;
        if (!res.first) res = temp;
        else ans.push_back(temp.second);
    }
    if (!res.first && isbroken[node]) return {1,node};
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> adj_list[n+1];
    set<pair<int,int>> broken;
    rep(i,0,n-1){
        int node1,node2,isBroken;
        cin >> node1 >> node2 >> isBroken;
        adj_list[node1].pb(node2);
        adj_list[node2].pb(node1);
        if(isBroken == 2) {
            broken.insert({node1,node2});
            broken.insert({node2,node1});
        }
    } 
    // build isbroken
    vector<bool> isbroken(n+1,0);
    dfs1(adj_list,1,0,broken,isbroken);

    vector<int> ans;
    auto res = dfs(adj_list,1,0,isbroken,ans);
    if (res.first) ans.push_back(res.second);
    cout << ans.size() << "\n";
    for (int num:ans) cout << num << " ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}