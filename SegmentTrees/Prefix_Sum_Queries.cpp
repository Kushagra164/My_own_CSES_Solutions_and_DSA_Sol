#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define int long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

class Node{
    public:
        int sum=0;
        int mx_pref;
};

void buildSegTree(vector<Node> &SegTree,vector<int> &arr,int idx,int low,int high){
    if (low == high){
        SegTree[idx].sum = arr[low];
        SegTree[idx].mx_pref = arr[low];
        return ;
    }
    int mid = (low+high)>>1;
    buildSegTree(SegTree,arr,(2*idx)+1,low,mid);
    buildSegTree(SegTree,arr,(2*idx)+2,mid+1,high);
    SegTree[idx].mx_pref = max(SegTree[(2*idx)+1].mx_pref,SegTree[(2*idx)+1].sum+SegTree[(2*idx)+2].mx_pref);
    SegTree[idx].sum = SegTree[(2*idx)+1].sum+SegTree[(2*idx)+2].sum;

    return ;
}

void update(vector<Node> &SegTree,int idx,int low,int high,int tar_idx,int val){
    if (low == high && low == tar_idx){
        SegTree[idx].mx_pref = val;
        SegTree[idx].sum = val;
        return ;
    }

    if (low>tar_idx || high<tar_idx) return ;
    int mid = (low+high)>>1;
    if (tar_idx <= mid) update(SegTree,(2*idx)+1,low,mid,tar_idx,val);
    else update(SegTree,(2*idx)+2,mid+1,high,tar_idx,val);
    SegTree[idx].mx_pref = max(SegTree[(2*idx)+1].mx_pref,SegTree[(2*idx)+1].sum+SegTree[(2*idx)+2].mx_pref);
    SegTree[idx].sum = SegTree[(2*idx)+1].sum+SegTree[(2*idx)+2].sum;

    return ;
}

Node query(vector<Node> &SegTree,int idx,int low,int high,int l,int r){
    if (l<=low && high<=r) return SegTree[idx];
    if (l>high || r<low) return {0,0};
    int mid = (low+high)>>1;
    auto q1 = query(SegTree,(2*idx)+1,low,mid,l,r);
    auto q2 = query(SegTree,(2*idx)+2,mid+1,high,l,r);
    return {q1.sum+q2.sum,max(q1.mx_pref,q1.sum+q2.mx_pref)};
}

void solve() {
    
    int n,q;
    cin >> n >> q;
    
    vector<int> arr(n);
    for (signed i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<Node> SegTree(4*n);
    buildSegTree(SegTree,arr,0,0,n-1);
    while(q--){
        int type;
        cin >> type;
        if (type == 1){
            int idx,val;
            cin >> idx >> val;
            update(SegTree,0,0,n-1,idx-1,val); 
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << max(query(SegTree,0,0,n-1,l-1,r-1).mx_pref,1LL*0) << "\n"; 
        }
    }

    return ;
}

signed main() {
    solve();
    return 0;
}