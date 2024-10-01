#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void dfs(vector<int> adj_list[],int node,int par,int &timer,vector<int> &eulerTour,map<int,int> &timein,map<int,int> &timeout,vector<int> &vals){
    timein[node] = timer;
    eulerTour.push_back(vals[node]);
    timer++;
    for (int child:adj_list[node]){
        if (child != par){
            dfs(adj_list,child,node,timer,eulerTour,timein,timeout,vals);
        }
    }
    eulerTour.push_back(-1*vals[node]);
    timeout[node] = timer;
    timer++;

}

void buildSegTree(vector<int> &eulerTour,vector<long long> &SegTree,int idx,int low,int high){
    if (low == high){
        SegTree[idx] = 1LL*eulerTour[low];
        return;
    }
    int mid = (low+high)>>1;
    buildSegTree(eulerTour,SegTree,(2*idx)+1,low,mid);
    buildSegTree(eulerTour,SegTree,(2*idx)+2,mid+1,high);
    SegTree[idx] = SegTree[(2*idx)+1]+SegTree[(2*idx)+2];
    return;
}

void update(vector<long long> &SegTree,int idx,int low,int high,int t_idx,int val){
    if (low == high && low == t_idx){
        SegTree[idx] = 1ll*val;
        return ;
    }
    int mid = (low+high)>>1;
    if (mid>=t_idx) update(SegTree,(2*idx)+1,low,mid,t_idx,val);
    else update(SegTree,(2*idx)+2,mid+1,high,t_idx,val);
    SegTree[idx] = SegTree[(2*idx)+1]+SegTree[(2*idx)+2];
    return ;
}

long long query(vector<long long> &SegTree,int idx,int low,int high,int l,int r){
    if(low>=l && high<=r) return SegTree[idx];
    if (low>r  || l>high) return 0;
    int mid = (low+high)>>1;
    return query(SegTree,(2*idx)+1,low,mid,l,r)+query(SegTree,(2*idx)+2,mid+1,high,l,r);
}

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> val(n+1);
    rep(i,1,n+1) {
        cin >> val[i];
    }
    vector<int> adj_list[n+1];
    rep(i,0,n-1){
        int node1,node2;
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
    vector<int> eulerTour;
    int timer = 0;
    map<int,int> timein,timeout;
    dfs(adj_list,1,0,timer,eulerTour,timein,timeout,val);

    // Build SegTree
    int sz = eulerTour.size();
    vector<long long> SegTree(4*sz,0);
    buildSegTree(eulerTour,SegTree,0,0,sz-1);
    while(q--){
        int type;
        cin >> type;
        if (type == 1){
            int node,val;
            cin >> node >> val;
            update(SegTree,0,0,sz-1,timein[node],val);
            update(SegTree,0,0,sz-1,timeout[node],-1*val);
        }
        else{
            int node;
            cin >> node;
            cout << query(SegTree,0,0,sz-1,0,timein[node]) << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}