#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

class Node{
    public:
        int PminusI;
        int PplusI;
};

void buildSegTree(vector<Node> &SegTree,vector<int> &arr,int idx,int low,int high){
    if (low == high){
        SegTree[idx].PminusI = arr[low]-low;
        SegTree[idx].PplusI = arr[low] + low;
        return ; 
    }
    int mid = (low+high)>>1;
    buildSegTree(SegTree,arr,(2*idx)+1,low,mid);
    buildSegTree(SegTree,arr,(2*idx)+2,mid+1,high);
    SegTree[idx].PminusI = min(SegTree[(2*idx)+1].PminusI,SegTree[(2*idx)+2].PminusI);
    SegTree[idx].PplusI = min(SegTree[(2*idx)+1].PplusI,SegTree[(2*idx)+2].PplusI);
    return ;
}

void update(vector<Node> &SegTree,int idx,int low,int high,int tar_idx,int val){
    if (tar_idx == low && tar_idx == high){
        SegTree[idx].PminusI = val-low;
        SegTree[idx].PplusI = val + low;
        return ; 
    }
    int mid = (low+high)>>1;
    if (mid>=tar_idx) update(SegTree,(2*idx)+1,low,mid,tar_idx,val);
    else update(SegTree,(2*idx)+2,mid+1,high,tar_idx,val);
    SegTree[idx].PminusI = min(SegTree[(2*idx)+1].PminusI,SegTree[(2*idx)+2].PminusI);
    SegTree[idx].PplusI = min(SegTree[(2*idx)+1].PplusI,SegTree[(2*idx)+2].PplusI);
    return ;
}

int query(vector<Node> &SegTree,int idx,int low,int high,int l,int r,bool isPlus){
    if (low>r || high<l) return INT_MAX;
    if (low>=l && high<=r && isPlus) return SegTree[idx].PplusI;
    if (low>=l && high<=r && !isPlus) return SegTree[idx].PminusI;
    int mid = (low+high)>>1;
    return min(query(SegTree,(2*idx)+1,low,mid,l,r,isPlus),query(SegTree,(2*idx)+2,mid+1,high,l,r,isPlus));
}

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    rep(i,0,n) cin >> arr[i];
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
            int curr_idx;
            cin >> curr_idx;
            cout << min(query(SegTree,0,0,n-1,0,curr_idx-1,0)+curr_idx-1,query(SegTree,0,0,n-1,curr_idx-1,n-1,1)-curr_idx+1) << "\n";
        }   
    }

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}