#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define int long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void buildFlattenTree(vector<int> adj_list[],vector<int> &flattenTree,vector<pair<int,int>> &inOutIndex,int node,int par){
    flattenTree.pb(node);
    int f_idx = (int)flattenTree.size()-1;
    for (auto child:adj_list[node]){
        if (child != par) buildFlattenTree(adj_list,flattenTree,inOutIndex,child,node);
    }
    flattenTree.pb(node);
    int s_idx = (int)flattenTree.size()-1;
    inOutIndex[node] = {f_idx,s_idx};

    return ;
}

void buildSegTree(vector<int> &SegTree,vector<int> &flattenTree,vector<int> &values,int idx,int low,int high){
    if (low == high){
        SegTree[idx] = values[flattenTree[low]]; 
        return ;
    }
    int mid = (low+high)>>1;
    buildSegTree(SegTree,flattenTree,values,(2*idx)+1,low,mid);
    buildSegTree(SegTree,flattenTree,values,(2*idx)+2,mid+1,high);
    SegTree[idx] = SegTree[(2*idx)+1]+SegTree[(2*idx)+2];

    return ;
}

void update(vector<int> &SegTree,int idx,int low,int high,int t_idx,int val){
    if (low == high && low == t_idx){
        SegTree[idx] = val;
        return ;
    }
    if (low>t_idx || high<t_idx) return ;
    int mid = (low+high)>>1;
    update(SegTree,(2*idx)+1,low,mid,t_idx,val);
    update(SegTree,(2*idx)+2,mid+1,high,t_idx,val);
    SegTree[idx] = SegTree[(2*idx)+1] + SegTree[(2*idx)+2];

    return ;
}

int query(vector<int> &SegTree,int idx,int low,int high,int l,int r){
    if (low>r || high< l) return 0;
    if (low>=l && high<=r) return SegTree[idx];
    int mid = (low+high)>>1;
    return query(SegTree,(2*idx)+1,low,mid,l,r)+query(SegTree,(2*idx)+2,mid+1,high,l,r);
}

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> values(n+1);
    values[0]=0;
    for (int i=1;i<=n;i++) cin >> values[i];
    vector<int> adj_list[n+1];
    for (int i=0;i<n-1;i++){
        int node1,node2;
        cin >> node1 >> node2;
        adj_list[node1].pb(node2);
        adj_list[node2].pb(node1);
    }

    // Step1 : Build Flatten Tree 
    vector<int> flattenTree;
    // map<int,pair<int,int>> inOutIndex;
    vector<pair<int,int>> inOutIndex(n+1);
    buildFlattenTree(adj_list,flattenTree,inOutIndex,1,0);

    // Step2 : Build SegMent Tree on top of flattenTree
    int sz = flattenTree.size();
    vector<int> SegTree(4*sz);
    buildSegTree(SegTree,flattenTree,values,0,0,sz-1); 

    // cout << "print flatten tree\n";
    // for (auto num:flattenTree) cout << num << " ";
    // cout << "\n";

    // Step3 : Process Queries
    while(q--){
        int type;
        cin >> type;
        // cout << "ok\n";
        if (type == 1){
            int node,val;
            cin >> node >> val;
            // cout << "ok\n";
            update(SegTree,0,0,sz-1,inOutIndex[node].first,val);
            update(SegTree,0,0,sz-1,inOutIndex[node].second,val);
            // cout << "ok1\n";
            // for (auto num:SegTree) cout << num << " " ;
            // cout << "\n";
        }
        else {
            int node;
            cin >> node;
            // for (auto num:SegTree) cout << num << " " ;
            // cout << "\n";
            cout << (query(SegTree,0,0,sz-1,inOutIndex[node].first,inOutIndex[node].second))/2 << "\n";
        }
    }
}

signed main() {
    solve();
    return 0;
}