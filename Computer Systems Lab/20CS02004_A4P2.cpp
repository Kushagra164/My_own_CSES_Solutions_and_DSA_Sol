#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007
 
using namespace std;
 
//Articulation Points/Cut Vertices in undirected graph

// Input:
// n m                 // n-> no. of nodes m -> no. of edges
// a b ..              // denoting edge from a to b

// Output
// n                   // n-> no. of cut vertices
// a b ..              // a,b .. are the cut vertices
 
int timer1=1;
 
void dfs_for_finding_articulation_points(vector<int> adj_list[],int node,int parent,vector<bool> &vis,int time[],int low[],vector<bool> &mark){
    vis[node]=1;
    time[node]=low[node]=timer1;
    timer1++;
    int cnt_child=0;
    for (auto x:adj_list[node]){
        if (x==parent) continue;
        if (!vis[x]){
            dfs_for_finding_articulation_points(adj_list,x,node,vis,time,low,mark);
            low[node]=min(low[node],low[x]);
            if (low[x]>=time[node] && parent!=-1) mark[node]=1;
            cnt_child++;
        }
        else {
            low[node]=min(low[node],time[x]);
        }
    }
    if (cnt_child>1 && parent==-1) mark[node]=1;
    return ;
}
 
vector<int> FindArticulationPoints(vector<int> adj_list[],int n){
    // Assume 0 based Indexing
    vector<bool> vis(n+1,0),mark(n+1,0);
    int time[n+1],low[n+1];
    for (int i=1;i<=n;i++){
        if (!vis[i]) dfs_for_finding_articulation_points(adj_list,i,-1,vis,time,low,mark) ;
    }
    vector<int> art_points;
    for (int i=1;i<=n;i++) if (mark[i]==1) art_points.push_back(i);
    return art_points;
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
    vector<int> ans = FindArticulationPoints(adj_list,n);
    cout << ans.size() << "\n";
    for (auto x:ans) cout << x << " ";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}