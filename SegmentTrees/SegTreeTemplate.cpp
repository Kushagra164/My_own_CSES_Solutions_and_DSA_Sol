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
    int val;
};

void buildSegTree(vector<int> &arr,vector<Node> &SegTree,int idx,int low,int high){
    if (low == high){
        SegTree[idx].val = arr[low];
        return ;
    }
    int mid = (high+low)>>1;
    buildSegTree(arr,SegTree,(2*idx)+1,low,mid);
    buildSegTree(arr,SegTree,(2*idx)+2,mid+1,high);
    // do operation 
    // SegTree[idx].val = SegTree[(2*idx)+1] op SegTree[(2*idx)+2];
    return ;
}

void PointUpdate(vector<Node> &SegTree,int idx,int low,int high,int target_idx,int val){
    if (low == high && low == target_idx){
        SegTree[idx].val = val;
        return ;
    }
    if (low >target_idx || high<target_idx) return ;
    int mid = (low+high)>>1;
    PointUpdate(SegTree,(2*idx)+1,low,mid,target_idx,val);
    PointUpdate(SegTree,(2*idx)+2,mid+1,high,target_idx,val);
    // do op
    // SegTree[idx].val = SegTree[(2*idx)+1] op SegTree[(2*idx)+2];
    return;
}

int query(vector<Node> &SegTree,int idx,int low,int high,int l,int r){
    if (low>r || high<l) return 0;
    if (low>=l && high<=r) return SegTree[idx].val;
    int mid = (high+low)>>1;
    // do operation accordingly
    int op =0;
    return op;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }
    vector<Node> SegTree(4*n);
    buildSegTree(arr,SegTree,0,0,n-1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}