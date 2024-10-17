#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void dfs(int node,vector<int> adj_list[],vector<bool> &vis,vector<int> &subtree){
    subtree[node]=1;
    vis[node]=1;
    for (auto child:adj_list[node]){
        if (!vis[child]) dfs(child,adj_list,vis,subtree);
        subtree[node] += subtree[child];
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> adj_list[n+1];
    rep(i,0,m) {
        int node1,node2;
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
    }
    vector<bool> vis(n+1,0);
    vector<int> subtree(n+1,0);
    for(int i=1;i<=n;i++){
        if (!vis[i]){
            dfs(i,adj_list,vis,subtree);
        }
    }
    for(int i=1;i<=n;i++) cout << subtree[i] << " ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}