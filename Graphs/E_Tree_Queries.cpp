#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush
int timer;

void dfs(vector<int> adj_list[],int node,vector<int> &par,vector<pair<int,int>> &time,vector<int> &level){
    time[node].first = timer;
    for (auto child:adj_list[node]){
        if (child != par[node]){
            par[child] = node;
            timer++;
            level[child] = level[node]+1;
            dfs(adj_list,child,par,time,level);
        }
    }
    time[node].second = timer;
    timer++;
    return ;
}

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> adj_list[n+1];
    vector<pair<int,int>> time(n+1);
    vector<int> level(n+1,0),par(n+1,0);
    rep(i,0,n-1){
        int node1,node2;
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
    timer = 0;
    dfs(adj_list,1,par,time,level);
    while(q--){
        int k;
        cin >> k;
        // cout << k << "\n";
        int l_node=1,l_dis=0;
        vector<int> temp;
        for(int i=0;i<k;i++){
            int node;
            cin >> node;
            // cout << temp[i] << "\n";
            if (l_dis<level[node]){
                l_dis = level[node];
                l_node = node;
            }
            temp.pb(node);
            // cout << "works\n";
        }
        // cout << "works\n";
        bool ans = true;
        rep(i,0,k){
            if ((time[temp[i]].first<=time[l_node].first && time[temp[i]].second>=time[l_node].second)||(time[par[temp[i]]].first<=time[l_node].first && time[par[temp[i]]].second>=time[l_node].second)) continue;
            else ans = false;
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

}

signed main() {
    solve();
    return 0;
}