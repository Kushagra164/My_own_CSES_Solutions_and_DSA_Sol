#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007
 
using namespace std;
 
//Finding Bridges/Cut Edges in undirected graph
// Input:
// n m                 // n-> no. of nodes m -> no. of edges
// a b ..              // denoting edge from a to b

// Output
// k                   // no. of cut edges
// a b                 // denoting edge from a to b is cut edge
 
int timer=1;
 
void dfs_for_finding_bridges(vector<int> adj_list[],vector<bool> &vis,int node,int parent,int time[],int low[],vector<pair<int,int>> &bridges){
    vis[node]=1;
    time[node]=low[node]=timer;
    timer++;
    for (auto x:adj_list[node]){
        if (x==parent) continue;
        if (!vis[x]){
            dfs_for_finding_bridges(adj_list,vis,x,node,time,low,bridges);
            low[node]=min(low[node],low[x]);
            // Check for bridge
            if (low[x]>time[node]) bridges.push_back({x,node});
        }
        else{
            low[node]=min(low[node],low[x]);
        }
    }
}
 
vector<pair<int,int>> TarjansAlgoToFindBridges(vector<int> adj_list[],int n){
    // Assume 0 based indexing 
    vector<bool> vis(n+1,0);
    int tim[n+1],low[n+1];
    vector<pair<int,int>> bridges;
    dfs_for_finding_bridges(adj_list,vis,1,-1,tim,low,bridges);
    return bridges;
}
 
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> adj_list[n+1];
    for (int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj_list[x].pb(y);
        adj_list[y].pb(x);
    }
    vector<pair<int,int>> ans=TarjansAlgoToFindBridges(adj_list,n);
    cout << ans.size() << "\n";
    for (auto x:ans) cout << x.first << " " << x.second << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}