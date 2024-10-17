#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void dfs(vector<int> adj_list[],int node,int par,vector<int> &contri,vector<int> &subUnivCnt,int k){
    for (auto child:adj_list[node]){
        if (child != par){
            dfs(adj_list,child,node,contri,subUnivCnt,k);
            subUnivCnt[node] += subUnivCnt[child];
        }
    }
    contri[node] = min(subUnivCnt[node],2*k-subUnivCnt[node]);
}

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> contri(n+1,0),subUnivCnt(n+1,0);
    vector<int> adj_list[n+1];
    rep(i,0,2*k) {
        int node;
        cin >> node;
        subUnivCnt[node]++;
    }
    rep(i,0,n-1){
        int node1,node2;
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
    dfs(adj_list,1,0,contri,subUnivCnt,k);
    ll sum = 0;
    for (int num:contri) sum += 1LL*num;
    cout << sum ;
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}