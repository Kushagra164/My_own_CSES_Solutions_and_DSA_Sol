#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

double dfs(vector<int> adj_list[],int node,int par,double prob,vector<int> &level){
    if (node != 1 && (int)adj_list[node].size() == 1){
        return prob*((double)level[node]);
    }
    int n = adj_list[node].size();
    if (node == 1) prob = prob/((double)n);
    else prob /= ((double)(n-1));
    double sum = 0;
    for (auto child:adj_list[node]){
        if (child != par){
            level[child] = level[node]+1;
            sum += dfs(adj_list,child,node,prob,level);
        }
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    if (n == 1){
        cout << 0 ;
        return ;
    }
    vector<int> adj_list[n+1];
    rep(i,0,n-1) {
        int node1,node2;
        cin >> node1 >> node2;
        adj_list[node1].pb(node2);
        adj_list[node2].pb(node1);
    }
    double prob = 1.0;
    vector<int> level(n+1,0);
    cout << setprecision(15);
    cout  << dfs(adj_list,1,0,prob,level) ;

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}